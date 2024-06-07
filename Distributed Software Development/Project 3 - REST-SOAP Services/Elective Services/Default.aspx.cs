/*
 * Vincent Latona
 * Elective Service TryIt page
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.Serialization;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ElectiveServicesTryIt
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void wordCountButton_Click(object sender, EventArgs e)
        {
            if(inputString.Text != "") //String to count case
            {
                string input = inputString.Text; //Input string to pass to RESTful service
                Uri baseUri = new Uri("http://localhost:53172/Service1.svc/"); //Specify base URI
                UriTemplate myTemplate = new UriTemplate("StringWordCount?input={input}"); //Define the binding template
                Uri completeUri = myTemplate.BindByPosition(baseUri, input); //Define complete URI
                WebClient channel = new WebClient(); //Create Web Client
                byte[] rawData = channel.DownloadData(completeUri); //Download raw bytes from the service
                Stream memStream = new MemoryStream(rawData); //Convert bytes to a memory stream
                DataContractSerializer obj = new DataContractSerializer(typeof(int)); //Define serializer to take int
                string result = obj.ReadObject(memStream).ToString(); //Convert memory stream to string
                wordOutputLabel.Text = "Number of Words: " + result; //Display word count
            }
            else //Empty textbox case
            {
                wordOutputLabel.Text = "Please enter a string of words to be counted."; //Print error message
            }
        }

        protected void charCountButton_Click(object sender, EventArgs e)
        {
            if (inputChars.Text != "") //String to count case
            {
                string input = inputChars.Text; //Input characters to pass to RESTful service
                Uri baseUri = new Uri("http://localhost:53172/Service1.svc/"); //Specify base URI
                UriTemplate myTemplate = new UriTemplate("CharacterCount?input={input}"); //Define the binding template
                Uri completeUri = myTemplate.BindByPosition(baseUri, input); //Define complete URI
                WebClient channel = new WebClient(); //Create Web Client
                byte[] rawData = channel.DownloadData(completeUri); //Download raw bytes from the service
                Stream memStream = new MemoryStream(rawData); //Convert bytes to a memory stream
                DataContractSerializer obj = new DataContractSerializer(typeof(int)); //Define serializer to take int
                string result = obj.ReadObject(memStream).ToString(); //Convert memory stream to string
                charOutputLabel.Text = "Number of Characters: " + result; //Display character count
            }
            else //Empty textbox case
            {
                charOutputLabel.Text = "Please enter a string of characters to be counted."; //Print error message
            }
        }

        protected void specCharCountButton_Click(object sender, EventArgs e)
        {
            if(specInputChars.Text != "") //String count case
            {
                string specChars = specInputChars.Text; //Copy input string
                wsdlCounters.Service1Client counter = new wsdlCounters.Service1Client(); //Create service proxy
                int specCharCount = counter.SpecialCharacterCount(specChars); //Count special characters
                specCharOutputLabel.Text = "Number of Special Characters: " + specCharCount.ToString(); //Display special character count
            }
            else //Empty input case
            {
                specCharOutputLabel.Text = "Please enter a string with special characters to count."; //Print error message
            }
        }

        protected void occurrenceCountButton_Click(object sender, EventArgs e)
        {
            if((occurrencesStringInput.Text != "") && (occurrencesCharInput.Text != "")) //String and character case
            {
                char[] charInput = occurrencesCharInput.Text.ToCharArray(); //Convert string input to characters
                if(charInput.Length == 1) //Single character case
                {
                    string input = occurrencesStringInput.Text; //Copy input string
                    wsdlCounters.Service1Client counter = new wsdlCounters.Service1Client(); //Create service proxy
                    int occurrences = counter.CountOccurrences(input, charInput[0]); //Count occurrences
                    occurrenceOutputLabel.Text = "Number of Occurrences: " + occurrences.ToString(); //Display occurrence count
                }
                else //Multiple character case
                {
                    occurrenceOutputLabel.Text = "Please only enter a single character to count."; //Print error message
                }
            }
            else //Empty input cases
            {
                occurrenceOutputLabel.Text = "Please enter a string and a character to count."; //Print error message
            }
        }
    }
}