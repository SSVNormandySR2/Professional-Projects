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
    public partial class Staff1 : System.Web.UI.Page
    {
        /*
         * This function performs access control and populates the user information control
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["staffPassword"] != null) //Member logged-in case
            {
                if (Request.Cookies["staffUsername"] != null & Request.Cookies["staffUsername"].Value != "") //Logged-in staff case
                {
                    usernameLabel.Text = "Welcome staff member: " + Request.Cookies["staffUsername"].Value.ToString() + "!"; //Display username
                }
            }
            else //Unauthorized access
            {
                Response.Redirect("StaffLogin.aspx"); //Navigate to staff login page
            }

            string fileLocation = Path.Combine(HttpRuntime.AppDomainAppPath, @"App_Data\Member.xml"); //Get file location
            XmlDocument memberDoc = new XmlDocument(); //Create document object
            memberDoc.Load(fileLocation); //Load the Member.xml file
            XmlElement root = memberDoc.DocumentElement; //Get root element
            foreach (XmlNode node in root.ChildNodes) //Iterate over staff members
            {
                usernameView.Text += "Username: " + node["username"].InnerText + "\n"; //Add member info to display
            }
            memberDoc.Save(fileLocation); //Close XML file
        }

        /*
         * This function clears staff information and navigates to the home page
         */
        protected void homeButton_Click(object sender, EventArgs e)
        {
            Session["staffPassword"] = null; //Clear staff password
            Response.Cookies["staffUsername"].Value = ""; //Clear staff username
            Response.Redirect("Default.aspx"); //Navigate to home page
        }
    }
}