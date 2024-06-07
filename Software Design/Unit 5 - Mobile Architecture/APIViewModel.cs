/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Input;

namespace IdealWeightCalculator.ViewModels;

public class APIViewModel : INotifyPropertyChanged
{
    public ICommand calcIdealWeightAPICommand { get; set; } //Weight calculation command
    public ICommand linkNavigationCommand { get; set; } //Link navigation command
    public event PropertyChangedEventHandler PropertyChanged; //Property change event

    /*
     * PropertyChanged event handler for V/VM changes
     */
    public void OnPropertyChanged(string propertyName)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    private string idealW; //Ideal weight output object
    public string idealWeight { get => idealW; set { idealW = value; OnPropertyChanged(nameof(idealWeight)); } }

    private string risk; //Risk factor output object
    public string riskFactor { get => risk; set { risk = value; OnPropertyChanged(nameof(riskFactor)); } }

    private string height; //Height input object
    public string inputHeight { get => height; set { height = value; OnPropertyChanged(nameof(inputHeight)); } }

    private string weight; //Weight input object
    public string inputWeight { get => weight; set { weight = value; OnPropertyChanged(nameof(inputWeight)); } }

    private string gender; //Gender input object
    public string inputGender { get => gender; set { gender = value; OnPropertyChanged(nameof(inputGender)); } }

    private string error; //Error message output object
    public string outputError { get => error; set { error = value; OnPropertyChanged(nameof(outputError)); } }
    private List<string> links; //List for education links

    /*
     * This constructor instantiates the View Model
     */
    public APIViewModel()
    {
        calcIdealWeightAPICommand = new Command(calcIdealWeightAPI); //Bind command to function
        linkNavigationCommand = new Command(linkNavigation); //Bind command to function
        idealWeight = ""; //Initialize output variables
        riskFactor = "";
        outputError = "";
        inputHeight = ""; //Initialize input variables
        inputWeight = "";
        inputGender = "";
        links = new List<string>(); //Initialize the list of links
    }

    /*
     * This function calls the API to calculate the ideal weight
     */
    private async void calcIdealWeightAPI()
    {
        gender = gender.ToUpper(); //Cast gender to upper
        if (gender == "M"
            | gender == "F") //Valid gender case
        {
            bool validW = int.TryParse(weight, out int w);
            bool validH = int.TryParse(height, out int h);
            if (validW
                & validH) //Valid height and weight
            {
                outputError = ""; //Delete error message
                HttpClient client = new HttpClient(); //Initialize HTTP client
                try //Try to call API
                {
                    var response = await client.GetAsync("https://venus.sod.asu.edu/" +
                        "WSRepository/Services/IdealWeightService/Service.svc/IdealWeight?" +
                        "height=" + height + "&currentWeight=" + weight + "&sex=" + gender); //Call API
                    response.EnsureSuccessStatusCode(); //Check for success
                    var incoming = new WeightReturn();
                    using (StreamReader r = new StreamReader(response.Content.ReadAsStream())) //Read the content
                    {
                        string json = r.ReadToEnd(); //Read stream to the end
                        incoming = JsonSerializer.Deserialize<WeightReturn>(json); //Deserialize the JSON
                    }
                    links = incoming.HealthInformation.ToList(); //Make list of links
                    idealWeight = incoming.IdealWeight.ToString(); //Display ideal weight output
                    riskFactor = incoming.RiskFactor.ToString(); //Display risk factor output
                }
                catch (HttpRequestException ex) //Catch error
                {
                    outputError = ex.Message; //Display error message
                }
            }
            else if (!validW) //Invalid weight case
            {
                outputError = "Please enter your weight as an integer number."; //Display error message
            }
            else //Invalid height case
            {
                outputError = "Please enter your height as an integer number."; //Display error message
            }
        }
        else //Invalid gender case
        {
            outputError = "Please enter a valid gender (M/F)"; //Display error message
        }
    }

    /*
     * This function navigates to the first education link
     */
    private async void linkNavigation()
    {
        if(links != null & links.Count > 0) //Link list case
        {
            string[] link = links.ToArray(); //Convert links to array
            await Launcher.Default.OpenAsync(link[0]); //Navigate to the first link
        }
        else
        {
            outputError = "Please enter all inputs to seek education"; //Display error message
        }
    }

    /*
     * This is a JSON structure for the API return
     */
    public record struct WeightReturn
    (
        string[] HealthInformation, //List of education links
        int IdealWeight, //Calculated ideal weight
        string RiskFactor //Calculated risk factor
    );
}