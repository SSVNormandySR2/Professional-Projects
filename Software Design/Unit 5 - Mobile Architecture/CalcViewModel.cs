/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace IdealWeightCalculator.ViewModels;

public class CalcViewModel : INotifyPropertyChanged
{
    public ICommand calcIdealWeightCommand { get; set; } //Weight calculation command
    public event PropertyChangedEventHandler PropertyChanged; //Property change event

    /*
     * PropertyChanged event handler for V/VM changes
     */
    public void OnPropertyChanged(string propertyName)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    private string iWeight; //Ideal weight output object
    public string idealWeight { get => iWeight; set { iWeight = value; OnPropertyChanged(nameof(idealWeight)); } }

    private string ind; //Indicator output object
    public string indicator { get => ind; set { ind = value; OnPropertyChanged(nameof(indicator)); } }

    private string error; //Error message output object
    public string errorMsg { get => error; set { error = value; OnPropertyChanged(nameof(errorMsg)); } }

    private string inputWeight; //Weight input object
    public string inputW { get => inputWeight; set { inputWeight = value; OnPropertyChanged(nameof(inputW)); } }

    private string inputHeight; //Height input object
    public string inputH { get => inputHeight; set { inputHeight = value; OnPropertyChanged(nameof(inputH)); } }

    private string inputGender; //Gender input object
    public string inputG { get => inputGender; set { inputGender = value; OnPropertyChanged(nameof(inputG)); } }

    /*
     * This constructor instantiates the ViewModel
     */
    public CalcViewModel()
    {
        calcIdealWeightCommand = new Command(calcIdealWeight);
        idealWeight = ""; //Initialize output variables
        indicator = "";
        errorMsg = "";
        inputW = ""; //Initialize input variables
        inputH = "";
        inputG = "";
    }

    /*
     * This function computes the ideal weight and displays the outputs to the UI
     */
    private void calcIdealWeight()
    {
        inputGender = inputGender.ToUpper(); //Cast gender to upper
        if (inputGender == "M"
            | inputGender == "F") //Valid gender case
        {
            bool validW = int.TryParse(inputWeight, out int w);
            bool validH = int.TryParse(inputHeight, out int h);
            if (validW
                & validH) //Valid height and weight
            {
                errorMsg = ""; //Delete error message
                double ideal = 100 + (h - 60) * 5; //Calculate ideal weight
                idealWeight = Math.Round(ideal, 2).ToString() + " pounds"; //Display to UI
                if (w >= 15 + ideal) //Obese case
                {
                    indicator = "Obese"; //Display to UI
                }
                else if (w >= 10 + ideal) //Pre-Obese case
                {
                    indicator = "Pre-Obese"; //Display to UI
                }
                else if (w >= ideal - 5) //Normal case
                {
                    indicator = "Normal"; //Display to UI
                }
                else //Underweight case
                {
                    indicator = "Underweight"; //Dispaly to UI
                }
            }
            else if (!validW) //Invalid weight case
            {
                errorMsg = "Please enter your weight as an integer number."; //Display error message
            }
            else //Invalid height case
            {
                errorMsg = "Please enter your height as an integer number."; //Display error message
            }
        }
        else //Invalid gender case
        {
            errorMsg = "Please enter a valid gender (M/F)"; //Display error message
        }
    }
}
