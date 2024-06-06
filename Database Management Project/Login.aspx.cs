/*
 * Vyom Khare
 * Vincent Latona
 */

using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class Login : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function initializes the DB connection
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection
            cnn.Open(); //Open connection
        }

        /*
         * This function handles the login functionality
         */
        protected void loginButton_Click(object sender, EventArgs e)
        {
            if(emailInput.Text == "" | passwordInput.Text == "") //Empty fields case
            {
                loginOutput.Text = "Please fill in all fields."; //Print error message
                loginOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Check credentials case
            {
                string qemail = "'" + emailInput.Text + "'"; //Format email for query
                string hashed = Hash.hash(passwordInput.Text); //Hash password
                bool valid = false; //Redirect bool variable

                string query = "select userID, email, password from Users where email = " + qemail; //Query database for login
                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                while (reader.Read()) //Read query output
                {
                    if (reader["password"].ToString() == hashed) //Check credentials
                    {
                        loginOutput.Text = "Successful login!"; //Print success message
                        loginOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                        Session["UID"] = reader.GetString(0); //Log the user into the system
                        valid = true; //Set redirect to true
                    }
                    else //Failed login case
                    {
                        loginOutput.Text = "Incorrect password!"; //Print failure message
                        loginOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                    }
                }
                reader.Close(); //Close reader

                if(valid) //Redirect case
                {
                    cnn.Close(); //Close DB connection
                    Response.Redirect("UserActivity.aspx"); //Navigate to user activity page
                }
            }
        }

        /*
         * This function navigates to the user creation page
         */
        protected void createButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("Default.aspx"); //Navigate to create page
        }
    }
}