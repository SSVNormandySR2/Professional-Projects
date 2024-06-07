/*
 * Vyom Khare
 * Vincent Latona
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

namespace VLatonaAssignment8
{
    public partial class Member : System.Web.UI.Page
    {
        /*
         * This function loads the member username and performs additional access control
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["password"] == null) //Unauthorized access case
            {
                Response.Redirect("Login.aspx"); //Navigate to login page
            }
            else if (Request.Cookies["username"] != null) //Username cookie case
            {
                usernameLabel.Text = "Welcome " + Request.Cookies["username"].Value.ToString() + "!"; //Display username
            }
        }

        /*
         * This function performs the word counting service call
         */
        protected void fileUploadButton_Click(object sender, EventArgs e)
        {
            if (uploadControl.HasFile) //File chosen case
            {
                StreamReader reader = new StreamReader(uploadControl.PostedFile.InputStream); //Create reader
                try
                {
                    string fileLine = ""; //Initialize reader string
                    List<string> lines = new List<string>(); //Create line array
                    while ((fileLine = reader.ReadLine()) != null) //Read lines until end
                    {
                        lines.Add(fileLine); //Add file line to array
                    }
                    statusLabel.Text = "Upload Status: File transfer was successful!"; //Print success message
                    WordServices.Service1Client wordCounter = new WordServices.Service1Client(); //Create proxy
                    string count = wordCounter.WordCount(lines.ToArray()); //Call WordCount operation
                    countDisplay.Text = count; //Display word count
                }
                catch (Exception error)
                {
                    statusLabel.Text = "The following error occurred: " + error.Message; //Print error message
                }
                finally
                {
                    reader.Close(); //Close reader
                }
            }
            else //No file chosen case
            {
                statusLabel.Text = "Please select a text file to upload!"; //Print error message
            }
        }

        /*
         * This function performs the word filter service call
         */
        protected void filterButton_Click(object sender, EventArgs e)
        {
            if (filterInput.Text != "") //Input case
            {
                WordServices.Service1Client wordFilter = new WordServices.Service1Client(); //Create proxy
                filterDisplay.Text = wordFilter.WordFilter(filterInput.Text); //Filter string and display
            }
            else //No input case
            {
                filterDisplay.Text = "Please enter a string to be filtered."; //Print error message
            }
        }

        /*
         * This function performs the wrapped read string service call
         */
        protected void readButton_Click(object sender, EventArgs e)
        {
            if (readFileInput.Text != "") //Valid input case
            {
                FileServices.Service1Client readWriteClient = new FileServices.Service1Client(); //Create proxy
                string output = readWriteClient.readString(readFileInput.Text); //Call service
                readStringOutput.Text = output; //Set output text
            }
            else //Empty input case
            {
                readStringOutput.Text = "Please enter a valid file name."; //Print error message
            }
        }

        /*
         * This function performs the wrapped write string service call
         */
        protected void stringUploadButton_Click(object sender, EventArgs e)
        {
            if (storeStringInput.Text != "" & storeFileInput.Text != "") //Valid input case
            {
                FileServices.Service1Client readWriteClient = new FileServices.Service1Client(); //Create proxy
                uploadStatusLabel.Text = readWriteClient.writeString(storeFileInput.Text, storeStringInput.Text); //Call service
            }
            else //Empty inputs case
            {
                uploadStatusLabel.Text = "Please enter a valid string and file name."; //Print error message
            }
        }

        /*
         * This function performs the file upload service call
         */
        protected void fileUploadButton2_Click(object sender, EventArgs e)
        {
            if (fileUploadControl.HasFile) //Valid input case
            {
                List<string> fileContents = new List<string>(); //Initialize list of file lines
                StreamReader read = new StreamReader(fileUploadControl.PostedFile.InputStream); //Create stream reader
                string fileLine = ""; //Initialize reading string
                while ((fileLine = read.ReadLine()) != null) //Iterate over file lines
                {
                    fileContents.Add(fileLine); //Add file line
                }
                read.Close(); //Close stream reader
                FileServices.Service1Client readWriteClient = new FileServices.Service1Client(); //Create proxy
                string serverLocation = readWriteClient.storeFile(fileUploadControl.FileName, fileContents.ToArray()); //Call service
                fileUploadOutput.Text = "File Location: " + serverLocation; //Print file location
            }
            else //Empty input case
            {
                fileUploadOutput.Text = "Please enter a valid file."; //Print error message
            }
        }

        /*
         * This function performs the word count service call
         */
        protected void countWordsButton_Click(object sender, EventArgs e)
        {
            if (wordCountInput.Text != "") //String to count case
            {
                string input = wordCountInput.Text; //Input string to pass to RESTful service
                Uri baseUri = new Uri("http://webstrar91.fulton.asu.edu/page2/Service1.svc/"); //Specify base URI
                UriTemplate myTemplate = new UriTemplate("StringWordCount?input={input}"); //Define the binding template
                Uri completeUri = myTemplate.BindByPosition(baseUri, input); //Define complete URI
                WebClient channel = new WebClient(); //Create Web Client
                byte[] rawData = channel.DownloadData(completeUri); //Download raw bytes from the service
                Stream memStream = new MemoryStream(rawData); //Convert bytes to a memory stream
                DataContractSerializer obj = new DataContractSerializer(typeof(int)); //Define serializer to take int
                string result = obj.ReadObject(memStream).ToString(); //Convert memory stream to string
                wordCountOutput.Text = "Number of Words: " + result; //Display word count
            }
            else //Empty textbox case
            {
                wordCountOutput.Text = "Please enter a string of words to be counted."; //Print error message
            }
        }

        /*
         * This function performs the character count service call
         */
        protected void countCharactersButton_Click(object sender, EventArgs e)
        {
            if (characterCountInput.Text != "") //String to count case
            {
                string input = characterCountInput.Text; //Input characters to pass to RESTful service
                Uri baseUri = new Uri("http://webstrar91.fulton.asu.edu/page2/Service1.svc/"); //Specify base URI
                UriTemplate myTemplate = new UriTemplate("CharacterCount?input={input}"); //Define the binding template
                Uri completeUri = myTemplate.BindByPosition(baseUri, input); //Define complete URI
                WebClient channel = new WebClient(); //Create Web Client
                byte[] rawData = channel.DownloadData(completeUri); //Download raw bytes from the service
                Stream memStream = new MemoryStream(rawData); //Convert bytes to a memory stream
                DataContractSerializer obj = new DataContractSerializer(typeof(int)); //Define serializer to take int
                string result = obj.ReadObject(memStream).ToString(); //Convert memory stream to string
                characterCountOutput.Text = "Number of Characters: " + result; //Display character count
            }
            else //Empty textbox case
            {
                characterCountOutput.Text = "Please enter a string of characters to be counted."; //Print error message
            }
        }

        /*
         * This function performs the special character count service call
         */
        protected void specialCharacterButton_Click(object sender, EventArgs e)
        {
            if (specialCharacterInput.Text != "") //String count case
            {
                string specChars = specialCharacterInput.Text; //Copy input string
                wsdlCounters.Service1Client counter = new wsdlCounters.Service1Client(); //Create service proxy
                int specCharCount = counter.SpecialCharacterCount(specChars); //Count special characters
                specialCharacterOutput.Text = "Number of Special Characters: " + specCharCount.ToString(); //Display special character count
            }
            else //Empty input case
            {
                specialCharacterOutput.Text = "Please enter a string with special characters to count."; //Print error message
            }
        }

        /*
         * This function performs the occurrence count service call
         */
        protected void occurButton_Click(object sender, EventArgs e)
        {
            if ((occurStringInput.Text != "") && (occurCharacterInput.Text != "")) //String and character case
            {
                char[] charInput = occurCharacterInput.Text.ToCharArray(); //Convert string input to characters
                if (charInput.Length == 1) //Single character case
                {
                    string input = occurStringInput.Text; //Copy input string
                    wsdlCounters.Service1Client counter = new wsdlCounters.Service1Client(); //Create service proxy
                    int occurrences = counter.CountOccurrences(input, charInput[0]); //Count occurrences
                    occurCountOutput.Text = "Number of Occurrences: " + occurrences.ToString(); //Display occurrence count
                }
                else //Multiple character case
                {
                    occurCountOutput.Text = "Please only enter a single character to count."; //Print error message
                }
            }
            else //Empty input cases
            {
                occurCountOutput.Text = "Please enter a string and a character to count."; //Print error message
            }
        }
        
        /*
         * This function performs the character replacement service call
         */
        protected void replacementButton_Click(object sender, EventArgs e)
        {
            if (replaceStringInput.Text != string.Empty & replaceCharacterInput.Text != string.Empty & replacementCharacterInput.Text != string.Empty) //Filled fields case
            {
                if (replaceCharacterInput.Text.Length == 1 & replacementCharacterInput.Text.Length == 1) //Valid input case
                {
                    Uri baseAddr = new Uri("http://webstrar91.fulton.asu.edu/page7/Service1.svc/"); //Specify base URI
                    UriTemplate newTemp = new UriTemplate("replaceCharacters?input={input}&charToReplace={charToReplace}&replacementChar={replacementChar}"); //Define the binding template
                    Uri completeAddr = newTemp.BindByPosition(baseAddr, replaceStringInput.Text, replaceCharacterInput.Text, replacementCharacterInput.Text); //Define complete URI
                    WebClient channel = new WebClient(); //Create web client
                    byte[] byteArray = channel.DownloadData(completeAddr); //Download raw bytes from the service
                    Stream memStream = new MemoryStream(byteArray); //Convert bytes to a memory stream
                    DataContractSerializer serializer = new DataContractSerializer(typeof(string)); //Define serializer to take string
                    string output = serializer.ReadObject(memStream).ToString(); //Convert memory stream to string
                    replacedStringOutput.Text = output; //Display replaced string
                }
                else //Multicharacter case
                {
                    replacedStringOutput.Text = "Please enter only one character."; //Print error message
                }
            }
            else //Empty fields case
            {
                replacedStringOutput.Text = "Please make sure all text boxes are filled."; //Print error message
            }
        }

        /*
         * This function performs the word replacement service call
         */
        protected void replaceWordButton_Click(object sender, EventArgs e)
        {
            if (replaceWordStringInput.Text != string.Empty && replaceWordInput.Text != string.Empty && replacementWordInput.Text != string.Empty) //Filled fields case
            {
                string[] replaceWordArray = replacementWordInput.Text.Split(' '); //Array for replacement word
                string[] replacedWordArray = replaceWordInput.Text.Split(' '); //Array for word to replace
                if (replaceWordArray.Length == 1 && replacedWordArray.Length == 1) //Valid input case
                {
                    //set up connection to service
                    Uri baseAddr = new Uri("http://webstrar91.fulton.asu.edu/page7/Service1.svc/"); //Specify base URI
                    UriTemplate newTemp = new UriTemplate("replaceWords?input={input}&wordToReplace={wordToReplace}&replacementWord={replacementWord}"); //Define the binding template
                    Uri completeAddr = newTemp.BindByPosition(baseAddr, replaceWordStringInput.Text, replaceWordInput.Text, replacementWordInput.Text); //Define the complete URI
                    WebClient channel = new WebClient(); //Create web client
                    byte[] byteArray = channel.DownloadData(completeAddr); //Download raw bytes from the service
                    Stream memStream = new MemoryStream(byteArray); //Convert bytes to a memory stream
                    DataContractSerializer serializer = new DataContractSerializer(typeof(string)); //Define serializer to take string
                    string output = serializer.ReadObject(memStream).ToString(); //Convert memory stream to string
                    replacedWordOutput.Text = output; //Display replaced string
                }
                else //Multiword case
                {
                    replacedWordOutput.Text = "Please enter only one word."; //Print error message
                }
            }
            else //Empty input case
            {
                replacedWordOutput.Text = "Please make sure all text boxes are filled."; //Print error message
            }
        }

        /*
         * This function performs the character deletion service call
         */
        protected void deleteCharacterButton_Click(object sender, EventArgs e)
        {
            if (deleteCharacterStringInput.Text != string.Empty && deleteCharacterInput.Text != string.Empty) //Filled fields case
            {
                if (deleteCharacterInput.Text.Length == 1) //Valid input case
                {
                    char[] deleteCharArray = deleteCharacterInput.Text.ToCharArray(); //Convert input to array
                    wsdlDeletes.Service1Client deleter = new wsdlDeletes.Service1Client(); //Create proxy
                    string output = deleter.deleteCharacter(deleteCharacterStringInput.Text, deleteCharArray[0]); //Call service
                    deleteCharacterOutput.Text = output; //Display new string
                }
                else //Too many input characters case
                {
                    deleteCharacterOutput.Text = "Please enter only one character."; //Print error message
                }
            }
            else //Empty input case
            {
                deleteCharacterOutput.Text = "Please make sure all text boxes are filled."; //Print error message
            }
        }

        /*
         * This function performs the word deletion service call
         */
        protected void deleteWordButton_Click(object sender, EventArgs e)
        {
            if (deleteWordStringInput.Text != string.Empty && deleteWordInput.Text != string.Empty) //Filled fields case
            {
                string[] wordToDeleteArray = deleteWordInput.Text.Split(' '); //Split word input
                if (wordToDeleteArray.Length == 1) //
                {
                    wsdlDeletes.Service1Client deleter = new wsdlDeletes.Service1Client(); //Create proxy
                    string output = deleter.deleteWord(deleteWordStringInput.Text, deleteWordInput.Text); //Call service
                    deleteWordOutput.Text = output; //Display new string

                }
                else //Too many words case
                {
                    deleteWordOutput.Text = "Please enter only one word."; //Print error message
                }

            }
            else //Empty input case
            {
                deleteWordOutput.Text = "Please make sure all text boxes are filled."; //Print error message
            }
        }

        /*
         * This function redirects to the home page
         */
        protected void homeButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("Default.aspx"); //Navigate to home page
        }
    }
}