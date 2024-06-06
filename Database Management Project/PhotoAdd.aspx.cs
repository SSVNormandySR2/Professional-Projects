/*
 * Vyom Khare
 * Vincent Latona
 */

using Google.Protobuf.Collections;
using Google.Protobuf.WellKnownTypes;
using MySql.Data.MySqlClient;
using Org.BouncyCastle.Asn1.Ocsp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class PhotoAdd : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function populates the album and photo lists
         */
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
                    loadTables(num); //Populate tables
                }
            }
        }

        /*
         * This function fills the table viewers
         */
        private void loadTables(int uid)
        {
            string query = "select * from Albums as a where a.ownerID = " + uid; //Query database for all user albums
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            userAlbums.DataSource = reader; //Set query output as the table source
            userAlbums.DataBind(); //Bind display table
            reader.Close(); //Close reader

            query = "select p.photoID, p.albumID, p.caption from Photos as p, Albums as a where a.ownerID = " +
                uid + " and a.albumID = p.albumID"; //Query database for user photos
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            userPhotos.DataSource = reader; //Set query output as the table source
            userPhotos.DataBind(); //Bind display table
            reader.Close(); //Close reader
        }

        /*
         * This function handles adding photos
         */
        protected void addPhotoButton_Click(object sender, EventArgs e)
        {
            if(albumInput.Text == "" | captionInput.Text == "" | photoLoc.Text == "") //Empty fields case
            {
                addMessage.Text = "Please fill all fields to add a photo."; //Print error message
                addMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt add case
            {
                if(int.TryParse(albumInput.Text, out int aid)) //Valid album input case
                {
                    if (Session["UID"] != null) //Check user login
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse current user ID
                        {
                            if(validateAlbum(num, aid)) //Add case
                            {
                                int nextID = 0; //Variable for ext photo ID
                                string qcaption = "'" + captionInput.Text + "'";
                                string qloc = "'" + photoLoc.Text + "'";

                                string query = "select max(p.photoID) from Photos as p"; //Query database for next photoID
                                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                                while(reader.Read()) //Parse query result
                                {
                                    nextID = int.Parse(reader.GetString(0)); //Parse next ID
                                }
                                reader.Close(); //Close reader

                                nextID++; //Increment next ID

                                query = "insert into Photos values (" + nextID + ", " + aid + ", " + 
                                    qcaption + ", " + qloc + ")"; //Insertion query
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Parse query result
                                reader.Close(); //Close reader

                                loadTables(num); //Update tables

                                addMessage.Text = "Photo successfully added!"; //Print success message
                                addMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                            else //Invalid album case
                            {
                                addMessage.Text = "Please enter an album ID that exists and you own."; //Print error message
                                addMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Invalid album input case
                {
                    addMessage.Text = "Please enter the album ID as an integer."; //Print error message
                    addMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function validates albums for the user
         */
        private bool validateAlbum(int uid, int aid)
        {
            bool exists = false; //Boolean for validation
            string query = "select a.albumID from Albums as a where a.ownerID = " + uid; //Query database for all albums of the user
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while(reader.Read()) //Parse query results
            {
                if(reader.GetString(0) == aid.ToString()) //Valid album case
                {
                    exists = true; //Set valid
                    break;
                }
            }
            reader.Close(); //Close reader

            return exists; //Return validation boolean
        }

        /*
         * This function navigates to the photo viewer
         */
        protected void viewPhotosButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("PhotosView.aspx"); //Navigate to photo viewer
        }

        /*
         * This function handles deleting photos
         */
        protected void deletePhotoButton_Click(object sender, EventArgs e)
        {
            if(deleteInput.Text == "") //Empty field case
            {
                deleteMessage.Text = "Please enter a photo ID to delete."; //Print error message
                deleteMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt deletion case
            {
                if(int.TryParse(deleteInput.Text, out int pid)) //Valid photo input case
                {
                    if (Session["UID"] != null) //Check user login
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                        {
                            if(validatePhoto(num, pid)) //Delete case
                            {
                                string query = "delete from Photos as p where p.photoID = " + pid; //Deletion query
                                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Parse query results
                                reader.Close(); //Close reader

                                loadTables(num); //Update tables

                                deleteMessage.Text = "Photo successfully deleted."; //Print success message
                                deleteMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                            else //Invalid photo case
                            {
                                deleteMessage.Text = "Please enter a photo ID that exists and you own."; //Print error message
                                deleteMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Invalid input case
                {
                    deleteMessage.Text = "Please enter a photo ID as an integer."; //Print error message
                    deleteMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function validates a photo to be deleted
         */
        private bool validatePhoto(int uid, int pid)
        {
            bool valid = false; //Boolean for photo validation
            string query = "select p.photoID from Photos as p, Albums as a where a.albumID = p.albumID and a.ownerID = " + uid; //Query database for all user photos
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while (reader.Read()) //Parse query results
            {
                if (reader.GetString(0) == pid.ToString()) //Valid photo case
                {
                    valid = true; //Set valid
                    break;
                }
            }
            reader.Close(); //Close reader

            return valid; //Return validation boolean
        }

        /*
         * This function adds tags to a given photo
         */
        protected void tagButton_Click(object sender, EventArgs e)
        {
            if(photoIDInput.Text == "" | tagInput.Text == "") //Empty inputs case
            {
                tagMessage.Text = "Please fill all fields to add a tag."; //Print error message
                tagMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt tag case
            {
                if(int.TryParse(photoIDInput.Text, out int pid)) //Valid input photo ID
                {
                    if (Session["UID"] != null) //Check user login
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user ID
                        {
                            if(validTag(num, pid, tagInput.Text)) //Add tag case
                            {
                                string qtag = "'" + tagInput.Text + "'"; //Format tag for query

                                string query = "insert into Tags values(" + pid + ", " + qtag + ")"; //Insertion query
                                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Parse query results
                                reader.Close(); //Close reader

                                tagMessage.Text = "Tag added to photo successfully!"; //Print success message
                                tagMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                        }
                    }
                }
                else //Invalid photo ID input
                {
                    tagMessage.Text = "Please enter the photo ID as an integer."; //Print error message
                    tagMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function validates a given photo and tag
         */
        private bool validTag(int uid, int pid, string tagContent)
        {
            bool validPhoto = validatePhoto(uid, pid); //Boolean for photo validation

            if(validPhoto) //Valid photo case
            {
                bool validTag = true; //Boolean for tag validation
                string query = "select t.tag from Tags as t where t.photoID = " + pid; //Query database for all tags associated with the photo
                MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                while (reader.Read()) //Parse query results
                {
                    if (reader.GetString(0) == tagContent) //Valid photo case
                    {
                        validTag = false; //Set invalid
                        tagMessage.Text = "The tag has already been added to this photo."; //Print error message
                        tagMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                        break;
                    }
                }
                reader.Close(); //Close reader

                return validTag; //Return tag validation boolean
            }

            tagMessage.Text = "Please enter a photo ID that you own."; //Print error message
            tagMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            return validPhoto; //Return photo validation boolean
        }

        /*
         * This function navigates to the top tags page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("TopTags.aspx");
        }
    }
}