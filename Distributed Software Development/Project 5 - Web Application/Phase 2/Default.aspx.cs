/*
 * Vyom Khare
 * Vincent Latona
 */

using HashLibrary;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace VLatonaAssignment8
{
    public partial class _Default : Page
    {
        /*
         * This function initializes the page with user information
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            sessionLabel.Text = "Current Number of Active Users: " + Application["SessionCounter"].ToString(); //Update session counter
            if (Session["password"] != null) //Member logged-in case
            {
                if (Request.Cookies["username"] != null & Request.Cookies["username"].Value != "") //Logged-in user case
                {
                    usernameLabel.Text = "Welcome " + Request.Cookies["username"].Value.ToString() + "!"; //Display username
                }
            }
            else //Visitor case
            {
                usernameLabel.Text = "Welcome visitor, register and login to see your username and access member services!"; //Display login text
            }
        }

        /*
         * This function will perform access control to the member page
         */
        protected void memberButton_Click(object sender, EventArgs e)
        {
            if (Session["password"] == null) //Unauthorized access case
            {
                Response.Redirect("Login.aspx"); //Navigate to login page
            }
            else //Authorized access case
            {
                Response.Redirect("Member.aspx"); //Navigate to member page
            }
        }

        /*
         * This function will perform access control to the staff page
         */
        protected void staffButton_Click(object sender, EventArgs e)
        {
            if(adminUsernameInput.Text != "" & adminPasswordInput.Text != "") //Filled fields case
            {
                if(adminUsernameInput.Text == "TA" & adminPasswordInput.Text == "Cse44598!") //Valid admin credentials
                {
                    adminLoginOutput.Text = "Login Status: Successful"; //Print success message
                    Session["adminPassword"] = Class1.hashFunction("Cse44598!"); //Save hashed admin password
                    Response.Cookies["adminUsername"].Value = "TA"; //Save username to cookies
                    Session["password"] = null; //Clear member password
                    Response.Cookies["username"].Value = ""; //Clear member username
                    Response.Redirect("StaffMgmt.aspx"); //Navigate to the staff page
                }
                else //Invalid admin credentials
                {
                    adminLoginOutput.Text = "Login Status: Invalid credentials"; //Print error message
                }
            }
            else //Empty input case
            {
                adminLoginOutput.Text = "Please enter an admin username and password to go to the staff page."; //Print error message
            }
        }

        /*
         * This function will take the user to the login page
         */
        protected void loginButton_Click(object sender, EventArgs e)
        {
            Session["password"] = null; //Clear member password
            Response.Cookies["username"].Value = ""; //Clear member username
            Response.Redirect("Login.aspx"); //Navigate to the login page
        }

        /*
         * This function will direct staff to login page
         */
        protected void staffPageButton_Click(object sender, EventArgs e)
        {
            Session["password"] = null; //Clear member password
            Response.Cookies["username"].Value = ""; //Clear member username
            Response.Redirect("StaffLogin.aspx"); //Navigate to staff login page
        }
    }
}