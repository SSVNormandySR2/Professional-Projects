/*
 * Vyom Khare
 * Vincent Latona
 */

using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class TagSearch : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the page with all tags
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection 
            cnn.Open(); //Open connection

            loadTags(); //Load all tags table
        }

        /*
         * This function loads the all tags table
         */
        private void loadTags()
        {
            string query = "select distinct t.tag from Tags as t"; //Query database for all tags
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            allTags.DataSource = reader; //Set query output as the table source
            allTags.DataBind(); //Bind display table
            reader.Close(); //Close reader
        }

        /*
         * This function searches for photos tagged by a given tag
         */
        protected void searchButton_Click(object sender, EventArgs e)
        {
            if(tagInput.Text == "") //Empty input case
            {
                tagSearchMessage.Text = "Please enter a tag to search."; //Print error message
                tagSearchMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Search case
            {
                if(validTag(tagInput.Text)) //Valid tag case
                {
                    //Session["UID"] = "4";
                    if (Session["UID"] != null) //Check user login
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse current user ID
                        {
                            loadTables(num, tagInput.Text); //Load photos that match

                            tagSearchMessage.Text = "Photos successfully loaded!"; //Print success message
                            tagSearchMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                        }
                    }
                }
                else //Invalid tag case
                {
                    tagSearchMessage.Text = "Please enter a valid tag to search."; //Print error message
                    tagSearchMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function checks for valid tags
         */
        private bool validTag(string tagText)
        {
            bool valid = false; //Boolean for valid tag
            string query = "select distinct t.tag from Tags as t"; //Query database for all tags
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            while(reader.Read()) //Parse query result
            {
                if(reader.GetString(0) == tagText) //Valid tag case
                {
                    valid = true; //Set boolean
                    break;
                }
            }
            reader.Close(); //Close reader

            return valid; //Return validation boolean
        }

        /*
         * This function loads output tables
         */
        private void loadTables(int uid, string tag)
        {
            string qtag = "'" + tag + "'"; //

            string query = "select p.photoID, p.caption from Photos as p, Tags as t where t.tag = " + qtag +
                " and t.photoID = p.photoID"; //Query database for photos with a tag
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            allPhotos.DataSource = reader; //Set query output as the table source
            allPhotos.DataBind(); //Bind display table
            reader.Close(); //Close reader

            query = "select p.photoID, p.caption from Photos as p, Tags as t, Albums as a\r\n" +
                "where a.albumID = p.albumID and a.ownerID = " + uid + " and t.tag = " + qtag +
                " and t.photoID = p.photoID"; //Query database for photos with a tag
            cmd = new MySqlCommand(query, cnn); //Create query command
            reader = cmd.ExecuteReader(); //Execute query
            yourPhotos.DataSource = reader; //Set query output as the table source
            yourPhotos.DataBind(); //Bind display table
            reader.Close(); //Close reader
        }

        /*
         * This function navigates to the comment search page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("CommentSearch.aspx"); //Navigate to comment search page
        }

        /*
         * This function displays a given photo
         */
        protected void photoSearch_Click(object sender, EventArgs e)
        {
            if(photoInput.Text == "") //Empty input case
            {
                photoViewMessage.Text = "Please enter a photo ID to view the photo."; //Print error message
                photoViewMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Attempt view case
            {
                if(int.TryParse(photoInput.Text, out int pid)) //Parse photo ID case
                {
                    if(validPhoto(pid)) //Valid photo case
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
         * This function performs the conjunctive tag search
         */
        protected void listSearchButton_Click(object sender, EventArgs e)
        {
            if(tagListInput.Text == "") //Empty list case
            {
                listSearchMessage.Text = "Please enter a list of tags, separated by spaces."; //Print error message
                listSearchMessage.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Search case
            {
                string[] tagList = tagListInput.Text.Split(' '); //Split into list of tags
                foreach(string tag in tagList) //Validate list
                {
                    if(!validTag(tag)) //Invalid tag case
                    {
                        listSearchMessage.Text = "Please enter a list of valid tags only."; //Print error message
                        listSearchMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                        return;
                    }
                }

                List<int> photos = new List<int>(); //Final list of intersections
                List<int> singleTagPhotos = new List<int>(); //List of photos with this tag

                string qtag; //Forward declare query variables
                string query;
                MySqlCommand cmd;
                MySqlDataReader reader;

                int pass = 1; //Initialize pass counter

                foreach(string tag in tagList) //Find photo intersection
                {
                    qtag = "'" + tag + "'"; //Format tag input
                    query = "select t.photoID from Tags as t where t.tag = " + qtag; //Query for photos matching the tag
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader(); //Execute query
                    while(reader.Read()) //Parse query result
                    {
                        if(int.TryParse(reader.GetString(0), out int mid)) //Parse photo ID
                        {
                            singleTagPhotos.Add(mid); //Add photo to list
                        }
                    }
                    reader.Close(); //Close reader

                    if(pass == 1) //Union case
                    {
                        foreach(int id in singleTagPhotos) //Add elements of current list to final list
                        {
                            photos.Add(id); //Add to final list
                        }
                    }
                    else //Intersection case
                    {
                        int[] final = photos.ToArray();
                        int[] run = singleTagPhotos.ToArray();

                        IEnumerable<int> q = from intID in final.Intersect(run)
                                             select intID; //Perform intersection
                        photos.Clear(); //Clear final list
                        foreach(int id in q) //Add intersected IDs to final list
                        {
                            photos.Add(id); //Add intersected ID
                        }
                    }

                    singleTagPhotos.Clear(); //Clear running list
                    pass++; //Increment pass
                }

                if(photos.Count() > 0) //List IDs case
                {
                    intersectList.Items.Clear(); //Clear the items list
                    foreach(int id in photos)
                    {
                        intersectList.Items.Add("Photo ID: " + id.ToString()); //Add item to list
                    }

                    listSearchMessage.Text = "Photos successfully listed!"; //Print success message
                    listSearchMessage.ForeColor = System.Drawing.Color.Green; //Make font green
                }
                else //Empty intersection case
                {
                    listSearchMessage.Text = "No photos contain all the given tags."; //Print error message
                    listSearchMessage.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }
    }
}