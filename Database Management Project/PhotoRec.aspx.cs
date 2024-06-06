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
using System.Xml.Linq;

namespace Phase3Application
{
    public partial class PhotoRec : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the recommendation table
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection 
            cnn.Open(); //Open connection

            //Session["UID"] = "4";
            if (Session["UID"] != null) //Check user login
            {
                if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                {
                    loadRecommended(num); //Load recommendation table
                }
            }
        }

        /*
         * This function loads the recommendation table displayed
         */
        private void loadRecommended(int uid)
        {
            string query = "select nonUserTags.photo, count(*) as score from\r\n" +
                "(select distinct t1.tag as tag, count(*) as occurrence\r\n" +
                "from Users as u1, Albums as a1, Photos as p1, Tags as t1\r\n" +
                "where u1.userID = " + uid + "\r\nand u1.userID = a1.ownerID \r\nand a1.albumID = p1.albumID " +
                "\r\nand p1.photoID = t1.photoID \r\ngroup by t1.tag \r\norder by occurrence desc\r\nlimit 5) as userTags" +
                "\r\ninner join\r\n(select t.photoID as photo, t.tag as tag from Tags as t, Photos as p, Albums as a" +
                "\r\nwhere t.photoID = p.photoID and p.albumID = a.albumID and a.ownerID != " + uid + ") as nonUserTags\r\n" +
                "on userTags.tag = nonUserTags.tag\r\ngroup by nonUserTags.photo \r\norder by score desc"; //Query database for recommendations
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            recommended.DataSource = reader; //Set query results as source
            recommended.DataBind(); //Bind to source
            reader.Close(); //Close reader
        }

        /*
         * This function validates if a photo exists
         */
        private bool validPhoto(int pid)
        {
            bool valid = false; //Boolean to validate photo
            string query = "select p.photoID from Photos as p"; //Query database for all photos
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while (reader.Read()) //Parse query result
            {
                if (reader.GetString(0) == pid.ToString()) //Valid tag case
                {
                    valid = true; //Set boolean
                    break;
                }
            }
            reader.Close(); //Close reader

            return valid; //Return validation boolean
        }

        /*
         * This function loads a photo
         */
        private void loadPhoto(int pid)
        {
            string query = "select p.loc from Photos as p where p.photoID = " + pid; //Query database for a given photo
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while (reader.Read()) //Parse query result
            {
                photoImage.ImageUrl = reader.GetString(0); //Load photo
                break;
            }
            reader.Close(); //Close reader
        }

        /*
         * This function loads a specified photo
         */
        protected void photoSearch_Click(object sender, EventArgs e)
        {
            if (photoInput.Text == "") //Empty input case
            {
                photoViewMessage.Text = "Please enter a photo ID to view the photo."; //Print error message
                photoViewMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt view case
            {
                if (int.TryParse(photoInput.Text, out int pid)) //Parse photo ID case
                {
                    if (validPhoto(pid)) //Valid photo case
                    {
                        loadPhoto(pid); //Load the photo

                        photoViewMessage.Text = "Photo successfully added."; //Print success message
                        photoViewMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                    }
                    else //Invalid photo case
                    {
                        photoViewMessage.Text = "Please enter a photo ID in the system."; //Print error message
                        photoViewMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                    }
                }
                else //Failed parsed case
                {
                    photoViewMessage.Text = "Please enter a photo ID as an integer."; //Print error message
                    photoViewMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        protected void logoutButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Session["UID"] = "0"; //Reset session user ID
            Response.Redirect("Login.aspx"); //Navigate to login page
        }
    }
}