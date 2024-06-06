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
    public partial class CommentSearch : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the DB connection
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection 
            cnn.Open(); //Open connection
        }

        /*
         * This function finds and lists comments
         */
        protected void commentSearchButton_Click(object sender, EventArgs e)
        {
            if(commentInput.Text == "") //Empty input case
            {
                commentMessage.Text = "Please enter a comment to search."; //Print error message
                commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Search case
            {
                if(validComment(commentInput.Text)) //Valid comment case
                {
                    listComments(commentInput.Text); //List matched users

                    commentMessage.Text = "Comments successfully listed!"; //Print success message
                    commentMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                }
                else //Invalid comment case
                {
                    commentMessage.Text = "Please enter a comment in the system."; //Print error message
                    commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function validates the comment input
         */
        private bool validComment(string comment)
        {
            bool valid = false; //Validation boolean for comment
            string query = "select distinct c.text from Comments as c"; //Query database for all comments
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while(reader.Read()) //Parse query result
            {
                if(reader.GetString(0) == comment) //Valid comment
                {
                    valid = true; //Validate comment
                    break;
                }
            }
            reader.Close(); //Close reader

            return valid; //Return validation boolean
        }

        /*
         * This function returns a list of users and the count of occurrences of the comment
         */
        private void listComments(string comment)
        {
            string qcomment = "'" + comment + "'"; //Format comment for query

            string query = "select u.firstName, u.lastName, count(*) as matched\r\n" +
                "from Users as u, Comments as c\r\nwhere u.userID = c.ownerID\r\nand c.text = " + qcomment + 
                "\r\ngroup by c.ownerID\r\norder by count(*) desc;"; //Query database for matched comments
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            comments.DataSource = reader; //Set query results as source
            comments.DataBind(); //Bind to source
            reader.Close(); //Close reader
        }

        /*
         * This function navigates to the photo recommendation page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("PhotoRec.aspx"); //Navigate to recommendation page
        }
    }
}