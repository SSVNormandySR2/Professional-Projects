/*
 * Vincent Latona
 */

using Google.Protobuf.WellKnownTypes;
using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class FriendSearch : System.Web.UI.Page
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
         * This function handles the search logic
         */
        protected void searchButton_Click(object sender, EventArgs e)
        {
            if (fNameInput.Text == "" | lNameInput.Text == "") ; //Empty fields case
            else //Search case
            {
                string qf = "'" + fNameInput.Text + "'"; //Format query inputs
                string ql = "'" + lNameInput.Text + "'";

                string query = "select userID, firstName, lastName from Users where firstName = " +
                    qf + " and lastName = " + ql; //Query database for user
                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                searchOutput.DataSource = reader; //Query results as source
                searchOutput.DataBind(); //Bind to source
                reader.Close(); //Close reader
            }
        }

        /*
         * This fucntion updates the list of friends of the current user
         */
        protected void updateFriends_Click(object sender, EventArgs e)
        {
            //Session["UID"] = "11";
            if (Session["UID"] != null) //Check if user is logged in
            {
                if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID for query
                {
                    string query = "select u.userID, u.firstName, u.lastName from Users as u, Friends as f where f.followerID = " + 
                        num + " and u.userID = f.followedID"; //Query database for friends
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    currentFriends.DataSource = reader; //Query results as source
                    currentFriends.DataBind(); //Bind to source
                    reader.Close(); //Close reader

                    query = "select u.userID, u.firstName, u.lastName from Users as u, Friends as f where f.followedID = " +
                        num + " and u.userID = f.followerID"; //Query database for other friends
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader(); //Execute query
                    otherFriends.DataSource = reader; //Query results as source
                    otherFriends.DataBind(); //Bind to source
                    reader.Close(); //Close reader
                }
            }
        }

        /*
         * This function handles friend adding logic
         */
        protected void addButton_Click(object sender, EventArgs e)
        {
            if(newFriendInput.Text != "" | docInput.Text != "") //Input case
            {
                string doc = docInput.Text; //String for date testing

                if (doc.Length != 10) //Incorrect doc length case
                {
                    addOutput.Text = "Your current date is not in the correct format"; //Print error
                    addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                    return; //Stop execution
                }
                else //Check for - characters
                {
                    string[] parts = doc.Split('-'); //Check for - character
                    if (parts.Length != 3) //Incorrect character case
                    {
                        addOutput.Text = "Your current date is not in the correct format"; //Print error
                        addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                        return; //Stop execution
                    }
                }

                if (int.TryParse(newFriendInput.Text, out int uid)) //Valid input case
                {
                    //Session["UID"] = "11";
                    if (Session["UID"] != null) //Check if user is logged in
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID for query
                        {
                            string query = "select userID from Users where userID = " + uid; //Query database for desired user
                            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                            bool valid = false; //Boolean for duplicate check
                            while (reader.Read()) //Read query output
                            {
                                if (reader["userID"].ToString() == uid.ToString()) //Check if user exists
                                {
                                    valid = true; //Trigger duplicate check
                                    break;
                                }
                            }
                            reader.Close(); //Close reader

                            if (valid) //Addition case
                            {
                                bool newAdd = true; //Boolean for new additions
                                query = "select u.userID, u.firstName, u.lastName from Users as u, Friends as f where f.followerID = " +
                                    num + " and u.userID = f.followedID"; //Query database for friends
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) //Read query output
                                {
                                    if (reader.GetString(0) == uid.ToString()) //Duplicate case
                                    {
                                        newAdd = false; //Indicate duplicate
                                        addOutput.Text = "You are already friends with this user."; //Print error
                                        addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                                        break;
                                    }
                                }
                                reader.Close(); //Close reader

                                if(newAdd) //New friend case
                                {
                                    string qdoc = "'" + doc + "'"; //Format doc for query
                                    query = "insert into Friends values(" + num + ", " + uid + ", "
                                        + qdoc + ")"; //Query to add friendship
                                    cmd = new MySqlCommand(query, cnn); //Create query command
                                    reader = cmd.ExecuteReader(); //Execute query
                                    while (reader.Read()) ; //Read query output
                                    reader.Close(); //Close reader
                                    addOutput.Text = "Friend successfully added. Update your friends list to see!"; //Print success message
                                    addOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                                }
                            }
                            else //Invalid user case
                            {
                                addOutput.Text = "There is no user with the user ID: " + uid; //Print error message
                                addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Input error case
                {
                    addOutput.Text = "Please enter the user ID as an iteger."; //Print error message
                    addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
            else //Empty input case
            {
                addOutput.Text = "Please enter the user ID to become friends with and today's date."; //Print error message
                addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
        }

        /*
         * This function navigates to the friend recommendations page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("FriendRecommendations.aspx"); //Navigate to next page
        }
    }
}
