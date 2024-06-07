/*
 * Vincent Latona
 * Vyom Khare
 */

using Google.Protobuf.WellKnownTypes;
using MySql.Data.MySqlClient;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Security.Cryptography;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class PhotosView : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection 
            cnn.Open(); //Open connection

            //Session["UID"] = "4";
            if (Session["UID"] != null) //Check user login
            {
                if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse current user ID
                {
                    string query = "select p.photoID, p.albumID, p.caption from Photos as p"; //Query database for photos
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    allPhotos.DataSource = reader; //Set query output as the table source
                    allPhotos.DataBind(); //Bind display table
                    reader.Close(); //Close reader

                    query = "select p.photoID, p.albumID, p.caption from Photos as p, Albums as a where a.ownerID = " + num + 
                        " and a.albumID = p.albumID"; //Query database for user photos
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader(); //Execute query
                    yourPhotos.DataSource = reader; //Set query output as the table source
                    yourPhotos.DataBind(); //Bind display table
                    reader.Close(); //Close reader

                    loadLikesAndComments(); //Load likes and comments tables
                }
            }
        }

        /*
         * This function loads the likes and comments tables
         */
        private void loadLikesAndComments()
        {
            string query = "select * from Likes"; //Query database for all likes
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            allLikes.DataSource = reader; //Set query output as the table source
            allLikes.DataBind(); //Bind display table
            reader.Close(); //Close reader

            query = "select * from Comments"; //Query database for all comments
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            allComments.DataSource = reader; //Set query output as the table source
            allComments.DataBind(); //Bind display table
            reader.Close(); //Close reader

            query = "select * from Tags"; //Query database for all tags
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            allTags.DataSource = reader; //Set query output as the table source
            allTags.DataBind(); //Bind display table
            reader.Close(); //Close reader
        }

        /*
         * This function fetches a list of photos given an album ID
         */
        protected void photoFetchButton_Click(object sender, EventArgs e)
        {
            if(photoAlbumInput.Text == "") //Empty input case
            {
                fetchOutput.Text = "Please enter an ID of an album to fetch."; //Print error message
                fetchOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt fetch case
            {
                if(int.TryParse(photoAlbumInput.Text, out int aid)) //Parse album input
                {
                    if (Session["UID"] != null) //Check if user is logged in
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                        {
                            bool valid = false; //Boolean for valid album
                            string query = "select a.albumID from Albums as a"; //Query database for album ID validation
                            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                            while(reader.Read()) //Parse query output
                            {
                                if(reader.GetString(0) == aid.ToString()) //Valid album case
                                {
                                    valid = true; //Set valid
                                    break;
                                }
                            }
                            reader.Close(); //Close reader

                            if(valid) //Valid album case
                            {
                                query = "select p.photoID, p.caption from Photos as p, Albums as a where a.albumID = " + 
                                    aid + " and p.albumID = " + aid; //Query database for photos from the album
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                photoList.DataSource = reader; //Set query output as the table source
                                photoList.DataBind(); //Bind display table
                                reader.Close(); //Close reader

                                fetchOutput.Text = "Photos successfully listed!"; //Print success message
                                fetchOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                            else //Invalid album case
                            {
                                fetchOutput.Text = "Please enter an album ID in the system."; //Print error message
                                fetchOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Failed parse case
                {
                    fetchOutput.Text = "Please enter an ID (integer) of an album to fetch."; //Print error message
                    fetchOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function displays photo information
         */
        private void displayPhotoInfo(int pid)
        {
            string query = "select p.photoID, p.caption, p.loc from Photos as p\r\nwhere p.PhotoID = " + pid; //Query database for photo information
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while (reader.Read()) //Parse query output
            {
                photoIDOutput.Text = "Photo ID: " + reader.GetString(0); //Set output displays
                photoCaptionOutput.Text = "Caption: " + reader.GetString(1);
                photoImage.ImageUrl = reader.GetString(2);
                break;
            }
            reader.Close(); //Close reader

            query = "select count(*) from Likes as l where l.photoID = " + pid; //Query database for like count
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            while (reader.Read()) //Parse query output
            {
                likeOutput.Text = "Likes: " + reader.GetString(0); //Set likes
                break;
            }
            reader.Close(); //Close reader

            query = "select u.userID, u.firstName, u.lastName from Users as u, Likes as l" +
                "\r\nwhere l.photoID = " + pid + " and l.userID = u.userID"; //Query database for user likes
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            photoLikes.DataSource = reader; //Bind query output to table
            photoLikes.DataBind(); //Bind table to data source
            reader.Close(); //Close reader

            query = "select t.tag from Tags as t where t.photoID = " + pid; //Query database for tags
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            photoTags.DataSource = reader; //Bind query output to table
            photoTags.DataBind(); //Bind table to data source
            reader.Close(); //Close reader

            query = "select u.userID, u.firstName, u.lastName, c.text, c.dateofComment from Comments as c, Users as u" +
                "\r\nwhere c.photoID = " + pid + " and u.userID = c.ownerID"; //Query database for comments
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            photoComments.DataSource = reader; //Bind query output to table
            photoComments.DataBind(); //Bind table to data source
            reader.Close(); //Close reader
        }

        /*
         * This function handles returning a specified photo and information
         */
        protected void photoView_Click(object sender, EventArgs e)
        {
            if(photoIDInput.Text == "") //Empty input case
            {
                loadOutput.Text = "Please enter a photo ID to view."; //Print error message
                loadOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt load case
            {
                if(int.TryParse(photoIDInput.Text, out int pid)) //Parse photo ID
                {
                    bool valid = false; //Boolean for valid photo
                    string query = "select p.photoID from Photos as p"; //Query database for photo ID validation
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    while (reader.Read()) //Parse query output
                    {
                        if (reader.GetString(0) == pid.ToString()) //Valid photo case
                        {
                            valid = true; //Set valid
                            break;
                        }
                    }
                    reader.Close(); //Close reader

                    if(valid) //Valid photo case
                    {
                        displayPhotoInfo(pid); //Display photo information

                        loadOutput.Text = "Photo successfully loaded!"; //Print success message
                        loadOutput.ForeColor = System.Drawing.Color.Green; //Make font red
                    }
                    else //Invalid photo case
                    {
                        loadOutput.Text = "Please enter a valid photo ID."; //Print error message
                        loadOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                    }
                }
                else //Failed parse case
                {
                    loadOutput.Text = "Please enter a photo ID as an integer."; //Print error message
                    loadOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function handles adding likes to a photo
         */
        protected void likeButton_Click(object sender, EventArgs e)
        {
            if (photoIDInput.Text == "") //Empty input case
            {
                likeMessage.Text = "Please enter a photo ID to like"; //Print error message
                likeMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt like case
            {
                if(int.TryParse(photoIDInput.Text, out int pid)) //Parse photo ID
                {
                    bool validPhoto = false; //Boolean for valid photo
                    string query = "select p.photoID from Photos as p"; //Query database for photo ID validation
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    while (reader.Read()) //Parse query output
                    {
                        if (reader.GetString(0) == pid.ToString()) //Valid photo case
                        {
                            validPhoto = true; //Set valid
                            break;
                        }
                    }
                    reader.Close(); //Close reader

                    if(validPhoto) //Valid photo ID case
                    {
                        if (Session["UID"] != null) //Check if user is logged in
                        {
                            if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                            {
                                bool valid = true; //Boolean for valid like
                                query = "select l.photoID from Likes as l where l.userID = " + num; //Query database for like validation
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) //Parse query output
                                {
                                    if (reader.GetString(0) == pid.ToString()) //Invalid like case
                                    {
                                        valid = false; //Set valid
                                        break;
                                    }
                                }
                                reader.Close(); //Close reader

                                if(valid) //Like case
                                {
                                    query = "insert into Likes values(" + num + ", " + pid + ")"; //Insertion query
                                    cmd = new MySqlCommand(query, cnn); //Create query command
                                    reader = cmd.ExecuteReader(); //Execute query
                                    while (reader.Read()) ; //Parse query output
                                    reader.Close(); //Close reader

                                    displayPhotoInfo(pid); //Display photo information

                                    likeMessage.Text = "Like successfully added to photo!"; //Print success message
                                    likeMessage.ForeColor = System.Drawing.Color.Green; //Make font green

                                    loadLikesAndComments(); //Update likes and comments
                                }
                                else //Invalid like case
                                {
                                    likeMessage.Text = "You cannot like this picture more than once"; //Print error message
                                    likeMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                                }
                            }
                        }
                    }
                    else //Invalid photo ID case
                    {
                        likeMessage.Text = "Please enter a valid photo ID to like"; //Print error message
                        likeMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                    }
                }
                else //Failed parse case
                {
                    likeMessage.Text = "Please enter a photo ID (as an integer) to like"; //Print error message
                    likeMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function handles adding comments to a photo
         */
        protected void commentButton_Click(object sender, EventArgs e)
        {
            if(dateInput.Text == "" | commentInput.Text == "" | photoIDInput.Text == "") //Empty inputs case
            {
                commentMessage.Text = "Please provide photo ID, a date, and comment text."; //Print error message
                commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt comment case
            {
                if (Session["UID"] != null) //Check if user is logged in
                {
                    if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                    {
                        if(int.TryParse(photoIDInput.Text, out int pid)) //Parse photo ID
                        {
                            string doc = dateInput.Text; //String for date testing

                            if (doc.Length != 10) //Incorrect doc length case
                            {
                                commentMessage.Text = "Your current date is not in the correct format"; //Print error message
                                commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                                return; //Stop execution
                            }
                            else //Check for - characters
                            {
                                string[] parts = doc.Split('-'); //Check for - character
                                if (parts.Length != 3) //Incorrect character case
                                {
                                    commentMessage.Text = "Your current date is not in the correct format"; //Print error message
                                    commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                                    return; //Stop execution
                                }
                            }

                            bool validPhoto = false; //Boolean for valid photo
                            string query = "select p.photoID from Photos as p"; //Query database for photo ID validation
                            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                            while (reader.Read()) //Parse query output
                            {
                                if (reader.GetString(0) == pid.ToString()) //Valid photo case
                                {
                                    validPhoto = true; //Set valid
                                    break;
                                }
                            }
                            reader.Close(); //Close reader

                            if(validPhoto) //Add comment case
                            {
                                string qdate = "'" + doc + "'"; //Format DB inputs
                                string qtext = "'" + commentInput.Text + "'";
                                int nextCID = 0; //Variable for next CID

                                query = "select max(c.commentID) from Comments as c"; //Query for next CID
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) //Parse query output
                                {
                                    nextCID = int.Parse(reader.GetString(0)); //Get max CID value
                                    break;
                                }
                                reader.Close(); //Close reader

                                nextCID++; //Increment for next CID

                                query = "insert into Comments values(" + nextCID + ", " + num + ", " + pid + ", " + qtext + 
                                    ", " + qdate + ")"; //Insertion query
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Parse query output
                                reader.Close(); //Close reader

                                displayPhotoInfo(pid); //Display photo information

                                commentMessage.Text = "Comment successfully added!"; //Print success message
                                commentMessage.ForeColor = System.Drawing.Color.Green; //Make font green

                                loadLikesAndComments(); //Update likes and comments
                            }
                            else //Invalid photo case
                            {
                                commentMessage.Text = "Please enter a photo ID as an integer."; //Print error message
                                commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                        else //Photo ID parse failure
                        {
                            commentMessage.Text = "Please enter a photo ID as an integer."; //Print error message
                            commentMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                        }
                    }
                }
            }
        }

        /*
         * This function handles navigation to photo adder
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Cose DB connection
            Response.Redirect("PhotoAdd.aspx"); //Navigate to photo adding page
        }

        /*
         * This function navigates to the albums page
         */
        protected void albumsButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("AlbumView.aspx"); //Navigate to album page
        }
    }
}
