/*
 * Vincent Latona
 * Services implemented: Services 4 and 2
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WordServicesTryIt
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        /*
         * This function tests the WordCount service (service 4)
         */
        protected void uploadButton_Click(object sender, EventArgs e)
        {
            if(uploadControl.HasFile) //File chosen case
            {
                StreamReader reader = new StreamReader(uploadControl.PostedFile.InputStream); //Create reader
                try
                {
                    string fileLine = ""; //Initialize reader string
                    List<string> lines = new List<string>(); //Create line array
                    while((fileLine = reader.ReadLine()) != null) //Read lines until end
                    {
                        lines.Add(fileLine); //Add file line to array
                    }
                    statusLabel.Text = "Upload Status: File transfer was successful!"; //Print success message
                    WordServices.Service1Client wordCounter = new WordServices.Service1Client(); //Create proxy
                    string count = wordCounter.WordCount(lines.ToArray()); //Call WordCount operation
                    countDisplay.Text = count; //Display word count
                }
                catch(Exception error)
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
         * This function tests the WordFilter service (service 2)
         */
        protected void filterButton_Click(object sender, EventArgs e)
        {
            if(filterInput.Text != "") //Input case
            {
                WordServices.Service1Client wordFilter = new WordServices.Service1Client(); //Create proxy
                filterDisplay.Text = wordFilter.WordFilter(filterInput.Text); //Filter string and display
            }
            else //No input case
            {
                filterDisplay.Text = "Please enter a string to be filtered."; //Print error message
            }
        }
    }
}