﻿/*
 * Vyom Khare
 * Vincent Latona
 */

using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;
using HashLibrary;

namespace VLatonaAssignment8
{
    public partial class LoginUC : System.Web.UI.UserControl
    {
        /*
         * This function calls the image generated by the user control
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            Image1.ImageUrl = "~/imageProcess.aspx"; //Get image from imageProcess
        }

        /*
         * This function performs access control to member services
         */
        protected void loginButton_Click(object sender, EventArgs e)
        {
            if(usernameInput.Text != "" & passwordInput.Text != "") //Filled fields case
            {
                string fileLocation = Path.Combine(HttpRuntime.AppDomainAppPath, @"App_Data\Member.xml"); //Get file location
                XmlDocument memberDoc = new XmlDocument(); //Create document object
                memberDoc.Load(fileLocation); //Load the Member.xml file
                XmlElement root = memberDoc.DocumentElement; //Get root element
                foreach (XmlNode node in root.ChildNodes) //Iterate over staff members
                {
                    if (node["username"].InnerText == usernameInput.Text) //User exists case
                    {
                        string hashedPassword = passwordInput.Text; //Get plaintext password
                        hashedPassword = Class1.hashFunction(passwordInput.Text); //Hash password value
                        if (node["password"].InnerText == hashedPassword) //Correct password case
                        {
                            memberDoc.Save(fileLocation); //Close XML file
                            Session["password"] = hashedPassword; //Save password to session
                            Response.Cookies["username"].Value = usernameInput.Text; //Save username to cookies
                            Response.Redirect("Member.aspx"); //Navigate to member page
                            return; //Abort remainder of function
                        }
                        else //Incorrect password case
                        {
                            memberDoc.Save(fileLocation); //Close XML file
                            loginOutput.Visible = true; //Show error message
                            loginOutput.Text = "Sorry, that password is not correct. Please try again."; //Print error message
                            return; //Abort remainder of function
                        }
                    }
                }
                memberDoc.Save(fileLocation); //Close XML file
                loginOutput.Visible = true; //Show error message
                loginOutput.Text = "The member account " + usernameInput.Text + " does not exist."; //Print error message
            }
            else //Empty input case
            {
                loginOutput.Visible = true; //Show error message
                loginOutput.Text = "Please enter both a username and a password to login."; //Print error message
            }
        }

        /*
         * This function will attempt to create a new member with credentials for access control
         */
        protected void verifyButton_Click(object sender, EventArgs e)
        {
            if(usernameInput.Text != "" & passwordInput.Text != "") //Filled fields case
            {
                if(verifyStringInput.Text == Session["generatedString"].ToString()) //Verified string case
                {
                    string fileLocation = Path.Combine(HttpRuntime.AppDomainAppPath, @"App_Data\Member.xml"); //Get file location
                    XmlDocument memberDoc = new XmlDocument(); //Create document object
                    memberDoc.Load(fileLocation); //Load the Member.xml file
                    XmlElement root = memberDoc.DocumentElement; //Get root element
                    foreach (XmlNode node in root.ChildNodes) //Iterate over staff members
                    {
                        if (node["username"].InnerText == usernameInput.Text) //User exists case
                        {
                            verifyOutput.Text = "Account with username " + usernameInput.Text + " already exists."; //Print error message
                            memberDoc.Save(fileLocation); //Close XML file
                            return; //Abort remainder of function
                        }
                    }
                    string hashedPassword = passwordInput.Text; //Get plaintext password
                    hashedPassword = Class1.hashFunction(passwordInput.Text); //Hash password value
                    XmlElement memberAccount = memberDoc.CreateElement("member", root.NamespaceURI); //Create member element
                    root.AppendChild(memberAccount); //Add new member to root
                    XmlElement memberUsername = memberDoc.CreateElement("username", root.NamespaceURI); //Create username element
                    memberUsername.InnerText = usernameInput.Text; //Assign username value to element
                    memberAccount.AppendChild(memberUsername); //Add username to member
                    XmlElement memberPassword = memberDoc.CreateElement("password", root.NamespaceURI); //Create password element
                    memberPassword.InnerText = hashedPassword; //Assign password value to element
                    memberAccount.AppendChild(memberPassword); //Add password to member
                    memberDoc.Save(fileLocation); //Close XML file
                    Session["password"] = hashedPassword; //Save password to session
                    Response.Cookies["username"].Value = usernameInput.Text; //Save username to cookies
                    Response.Redirect("Member.aspx"); //Navigate to member page
                }
                else //Invalid string
                {
                    verifyOutput.Text = "Sorry, that string is not correct. Please try again."; //Print error message
                }
            }
            else //Empty input case
            {
                verifyOutput.Text = "Please enter a username and a password for the new member."; //Print error message
            }
        }

        /*
         * This function generates a new image for verification
         */
        protected void imageButton_Click(object sender, EventArgs e)
        {
            if(strLenInput.Text != "") //Filled length case
            {
                string length = strLenInput.Text; //Save length input
                Session["userLength"] = length; //Assign length to session
                verifier.ServiceClient verifier = new verifier.ServiceClient(); //Create proxy
                string newString = verifier.GetVerifierString(length); //Generate new verifier string
                Session["generatedString"] = newString; //Assign verifier string to session
                Image1.Visible = true; //Make image visible
            }
            else //Empty length case
            {
                verifyOutput.Text = "Please enter the length of a new string."; //Print error message
            }
        }

        /*
         * This function redirects users to the home page
         */
        protected void homeButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("Default.aspx"); //Navigate to the home page
        }

        /*
         * This function will demonstrate the hash functionality
         */
        protected void hashButton_Click(object sender, EventArgs e)
        {
            if(hashInput.Text != "") //Filled input case
            {
                hashOutput.Text = Class1.hashFunction(hashInput.Text); //Display hashed output
            }
            else //Empty input case
            {
                hashOutput.Text = "Please enter a string to hash."; //Display error message
            }
        }
    }
}