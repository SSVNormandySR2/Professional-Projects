/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace VLatonaAssignment8
{
    public partial class Staff : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void addButton_Click(object sender, EventArgs e)
        {
            if(usernameInput.Text != "" & passwordInput.Text != "") //Filled fields case
            {
                string fileLocation = Path.Combine(HttpRuntime.AppDomainAppPath, @"App_Data\Staff.xml"); //Get file location
                XmlDocument staffDoc = new XmlDocument(); //Create document object
                staffDoc.Load(fileLocation); //Load the staff.xml file
                XmlElement root = staffDoc.DocumentElement; //Get root element
                foreach(XmlNode node in root.ChildNodes) //Iterate over staff members
                {
                    if (node["username"].InnerText == usernameInput.Text) //User exists case
                    {
                        output.Text = "Account with username " + usernameInput.Text + " already exists."; //Print error message
                        staffDoc.Save(fileLocation); //Close XML file
                        return; //Abort remainder of function
                    }
                }
                string hashedPassword = passwordInput.Text; //Save password value
                //hashedPassword = hashFunction(passwordInput.Text); //Hash password value
                XmlElement staffMember = staffDoc.CreateElement("staff-member", root.NamespaceURI); //Create staff member element
                root.AppendChild(staffMember); //Add staff member to root
                XmlElement staffUsername = staffDoc.CreateElement("username", root.NamespaceURI); //Create username element
                staffUsername.InnerText = usernameInput.Text; //Assign username value to element
                staffMember.AppendChild(staffUsername); //Add username to staff member
                XmlElement staffPassword = staffDoc.CreateElement("password", root.NamespaceURI); //Create password element
                staffPassword.InnerText = hashedPassword; //Assign password value to element
                staffMember.AppendChild(staffPassword); //Add password to staff member
                staffDoc.Save(fileLocation); //Save XML file
                output.Text = "Status: Staff Member successfully added."; //Display success message
            }
            else //Empty input case
            {
                output.Text = "Please enter both a username and a password for a staff member."; //Print error message
            }
        }

        protected void defaultButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("Default.aspx"); //Navigate to home page
        }
    }
}