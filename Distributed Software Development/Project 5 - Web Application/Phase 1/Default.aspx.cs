/*
 * Vincent Latona
 */

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
        protected void Page_Load(object sender, EventArgs e)
        {
            sessionLabel.Text = "Current Number of Active Users: " + Application["SessionCounter"].ToString(); //Update session counter
            //usernameLabel.Text = "Username: " + usernameCookie
        }

        /*
         * This function will perform access control to the member page
         */
        protected void memberButton_Click(object sender, EventArgs e)
        {
            //if: Cookies username and password are not blank
            //Response.Redirect("Member.aspx"); //Naviagate to the member page
            Response.Redirect("Login.aspx");
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
                    Response.Redirect("Staff.aspx"); //Navigate to the staff page
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
            Response.Redirect("Login.aspx"); //Navigate to the login page
        }
    }
}