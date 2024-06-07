/*
 * Vyom Khare
 * Vincent Latona
 */

using HashLibrary;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;

namespace VLatonaAssignment8
{
    public partial class StaffLogin : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        /*
         * This function redirects to the home page
         */
        protected void homeButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("Default.aspx"); //Navigate to home page
        }

        /*
         * This function performs staff access control
         */
        protected void loginButton_Click(object sender, EventArgs e)
        {
            if (staffUsernameInput.Text != "" & staffPasswordInput.Text != "") //Filled fields case
            {
                string fileLocation = Path.Combine(HttpRuntime.AppDomainAppPath, @"App_Data\Staff.xml"); //Get file location
                XmlDocument memberDoc = new XmlDocument(); //Create document object
                memberDoc.Load(fileLocation); //Load the Member.xml file
                XmlElement root = memberDoc.DocumentElement; //Get root element
                foreach (XmlNode node in root.ChildNodes) //Iterate over staff members
                {
                    if (node["username"].InnerText == staffUsernameInput.Text) //User exists case
                    {
                        string hashedPassword = staffPasswordInput.Text; //Get plaintext password
                        hashedPassword = Class1.hashFunction(staffPasswordInput.Text); //Hash password value
                        if (node["password"].InnerText == hashedPassword) //Correct password case
                        {
                            memberDoc.Save(fileLocation); //Close XML file
                            Session["staffPassword"] = hashedPassword; //Save password to session
                            Response.Cookies["staffUsername"].Value = staffUsernameInput.Text; //Save username to cookies
                            Response.Redirect("Staff.aspx"); //Navigate to staff page
                            return; //Abort remainder of function
                        }
                        else //Incorrect password case
                        {
                            memberDoc.Save(fileLocation); //Close XML file
                            loginOutput.Text = "Sorry, that password is not correct. Please try again."; //Print error message
                            return; //Abort remainder of function
                        }
                    }
                }
                memberDoc.Save(fileLocation); //Close XML file
                loginOutput.Text = "The member account " + staffUsernameInput.Text + " does not exist."; //Print error message
            }
            else //Empty input case
            {
                loginOutput.Text = "Please enter both a username and a password to login."; //Print error message
            }
        }
    }
}