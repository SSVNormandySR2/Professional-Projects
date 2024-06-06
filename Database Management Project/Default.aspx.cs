/*
 * Vincent Latona
 */

using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text;

namespace Phase3Application
{
    public partial class _Default : Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function initializes the DB connection
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Set connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection
            cnn.Open(); //Open connection
        }

        /*
         * This function handles error outputs
         */
        private void outputError(string msg)
        {
            createOutput.Text = msg; //Set error message
            createOutput.ForeColor = System.Drawing.Color.Red; //Make font red
        }

        /*
         * This function handles account creation
         */
        protected void Button1_Click(object sender, EventArgs e)
        {
            if(fNameInput.Text == "" | lNameInput.Text == "" | dobInput.Text == "" | 
                emailInput.Text == "" | passwordInput.Text == "") //Unfilled fields case
            {
                outputError("Please fill in all required fields."); //Print error
            }
            else //Possible creation case
            {
                string dob = dobInput.Text;

                if(dob.Length != 10) //Incorrect dob length case
                {
                    outputError("Your birthdate is not in the correct format"); //Print error
                    return; //Stop execution
                }
                else //Check for - characters
                {
                    string[] parts = dob.Split('-');
                    if (parts.Length != 3)
                    {
                        outputError("Please separate year, date, and month with '-'."); //Print error
                        return; //Stop execution
                    }
                }

                outputError(""); //Reset output message

                string email = emailInput.Text;
                string qemail = "'" + emailInput.Text + "'"; //Save email
                bool valid = true; //Bool for email validation

                string query = "select email from Users where email = " + qemail; //Query database if the email already exists
                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                while(reader.Read()) //Read query output
                {
                    if(email == reader["email"].ToString()) //Check if email already exists
                    {
                        outputError("Your input email already exists, please log into the system or use another email."); //Print error
                        valid = false; //Indicate termination
                        break; //Break loop
                    }
                }
                reader.Close(); //Close current reader

                if(valid) //Create user case
                {
                    createOutput.Text = ""; //Reset output message
                    string fName = "'" + fNameInput.Text + "'"; //Save required inputs
                    string lName = "'" + lNameInput.Text + "'";
                    dob = "'" + dob + "'";
                    string password = passwordInput.Text;
                    string hometown = "'" + hometownInput.Text + "'";
                    string gender = "'" + genderInput.SelectedValue + "'";
                    int nextID = 0; //Get next userID

                    query = "select max(userID) from Users"; //Query for current number of users
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader(); //Execute query
                    while(reader.Read())  //Read query output
                    {
                        nextID = int.Parse(reader["max(userID)"].ToString()); //Get current max userID
                        nextID++; //Increment for next ID
                        break; //Break loop
                    }
                    reader.Close(); //Close current reader
                    
                    string hashed = Hash.hash(password); //String for hashed password
                    hashed = "'" + hashed + "'"; //Convert to MySQL string

                    query = "insert into Users values(" + nextID + ", " + qemail + ", " + fName + ", " + 
                        lName + ", " + dob + ", " + hometown + ", " + gender + ", " + hashed + ")"; //Query to insert user
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader();
                    while (reader.Read()) ;
                    reader.Close();

                    Session["UID"] = nextID.ToString(); //Log user into the system
                    createOutput.Text = "New user has been created successfully"; //Print success message
                    createOutput.ForeColor = System.Drawing.Color.Green; //Make font green

                    Response.Redirect("UserActivity.aspx"); //Redirect to user activity page
                }
                else //Stop case
                {
                    return; //End execution
                }
            }
        }

        /*
         * This function handles page navigation
         */
        protected void NavButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("Login.aspx"); //Navigate to login page
        }
    }
}
