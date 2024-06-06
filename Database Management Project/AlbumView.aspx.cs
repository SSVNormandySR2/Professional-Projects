/*
 * Vyom Khare
 * Vincent Latona
 */

using Google.Protobuf.WellKnownTypes;
using MySql.Data.MySqlClient;
using Mysqlx.Crud;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Phase3Application
{
    public partial class AlbumView : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the albums into views
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
                    string query = "select * from Albums"; //Query database for all albums
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    allAlbums.DataSource = reader; //Set query output as the table source
                    allAlbums.DataBind(); //Bind display table
                    reader.Close(); //Close reader

                    query = "select * from Albums as a where a.ownerID = " + num; //Query database for all albums
                    cmd = new MySqlCommand(query, cnn); //Create query command
                    reader = cmd.ExecuteReader(); //Execute query
                    myAlbums.DataSource = reader; //Set query output as the table source
                    myAlbums.DataBind(); //Bind display table
                    reader.Close(); //Close reader
                }
            }
        }

        /*
         * This function handles album adding logic
         */
        protected void addButton_Click(object sender, EventArgs e)
        {
            if(albumNameInput.Text == "" | dateInput.Text == "") //Empty input case
            {
                addOutput.Text = "Please fill all fields to add a new album."; //Print error message
                addOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Validation/addition case
            {
                string doc = dateInput.Text; //String for date testing

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

                if (Session["UID"] != null) //Check if user is logged in
                {
                    if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse current user ID
                    {
                        int newID = 0; //Variable for album id

                        string query = "select max(a.albumID) from Albums as a"; //Query database for max album ID
                        MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                        MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                        while (reader.Read()) //Parse query output
                        {
                            newID = int.Parse(reader.GetString(0)); //Parse max album ID
                        }
                        reader.Close(); //Close reader
                        newID++; //Increment for new album

                        string qaid = "'" + newID.ToString() + "'"; //Format inputs
                        string qoid = "'" + num.ToString() + "'";
                        string qname = "'" + albumNameInput.Text + "'";
                        string qdate = "'" + doc + "'";

                        query = "insert into Albums values(" + qaid + ", " + qoid + ", " +
                            qname + ", " + qdate + ")"; //Insertion query
                        cmd = new MySqlCommand(query, cnn); //Create query command
                        reader = cmd.ExecuteReader(); //Execute query
                        while (reader.Read()) ; //Process output
                        reader.Close();

                        query = "select * from Albums"; //Query database for all albums
                        cmd = new MySqlCommand(query, cnn); //Create query command
                        reader = cmd.ExecuteReader(); //Execute query
                        allAlbums.DataSource = reader; //Set query output as the table source
                        allAlbums.DataBind(); //Bind display table
                        reader.Close(); //Close reader

                        query = "select * from Albums as a where a.ownerID = " + num; //Query database for all albums
                        cmd = new MySqlCommand(query, cnn); //Create query command
                        reader = cmd.ExecuteReader(); //Execute query
                        myAlbums.DataSource = reader; //Set query output as the table source
                        myAlbums.DataBind(); //Bind display table
                        reader.Close(); //Close reader

                        addOutput.Text = "New album successfully added!"; //Print success message
                        addOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                    }
                }
            }
        }

        /*
         * This function handles the deletion logic
         */
        protected void deleteButton_Click(object sender, EventArgs e)
        {
            if (albumIDInput.Text == "") //Empty input case
            {
                deleteOutput.Text = "Please enter the ID of the album to delete."; //Print error message
                deleteOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Deletion attempt case
            {
                if(int.TryParse(albumIDInput.Text, out int aid)) //Valid number case
                {
                    if (Session["UID"] != null) //Check if user is logged in
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user's ID
                        {
                            bool valid = false; //Boolean for deletion case
                            string query = "select a.albumID from Albums as a where a.ownerID = " +
                                    num; //Query database for user's albums
                            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                            while (reader.Read()) //Parse query output
                            {
                                if (aid.ToString() == reader.GetString(0)) //Check if album belongs to the user
                                {
                                    valid = true; //Set boolean
                                    break;
                                }
                            }
                            reader.Close(); //Close reader

                            if(valid) //Delete case
                            {
                                query = "delete from Albums as a where a.albumID = " + aid + 
                                    " and a.ownerID = " + num; //Deletion query
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Process output
                                reader.Close();

                                query = "select * from Albums"; //Query database for all albums
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                allAlbums.DataSource = reader; //Set query output as the table source
                                allAlbums.DataBind(); //Bind display table
                                reader.Close(); //Close reader

                                query = "select * from Albums as a where a.ownerID = " + num; //Query database for all albums
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                myAlbums.DataSource = reader; //Set query output as the table source
                                myAlbums.DataBind(); //Bind display table
                                reader.Close(); //Close reader

                                deleteOutput.Text = "Album successfully deleted"; //Print success message
                                deleteOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                            else //Error case
                            {
                                deleteOutput.Text = "Please enter the ID of an album you own."; //Print error message
                                deleteOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Invalid input case
                {
                    deleteOutput.Text = "Please enter the ID (integer number) of the album to delete."; //Print error message
                    deleteOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function handles the update logic
         */
        protected void updateButton_Click(object sender, EventArgs e)
        {
            if (updateIDInput.Text == "" | updateAlbumNameInput.Text == "") //Empty input case
            {
                updateOutput.Text = "Please enter the ID of the album to update and a new name for the album."; //Print error message
                updateOutput.ForeColor = System.Drawing.Color.Red; //Make font red
            }
            else //Update attempt case
            {
                if (int.TryParse(updateIDInput.Text, out int aid)) //Valid number case
                {
                    if (Session["UID"] != null) //Check if user is logged in
                    {
                        if (int.TryParse(Session["UID"].ToString(), out int num)) //Parse user's ID
                        {
                            bool valid = false; //Boolean for update case
                            string query = "select a.albumID from Albums as a where a.ownerID = " +
                                    num; //Query database for user's albums
                            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                            while (reader.Read()) //Parse query output
                            {
                                if (aid.ToString() == reader.GetString(0)) //Check if album belongs to the user
                                {
                                    valid = true; //Set boolean
                                    break;
                                }
                            }
                            reader.Close(); //Close reader

                            if (valid) //Update case
                            {
                                string qname = "'" + updateAlbumNameInput.Text + "'"; //Format new name

                                query = "update Albums as a set a.albumName = " + qname +
                                    " where a.albumID = " + aid; //Update query
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                while (reader.Read()) ; //Process output
                                reader.Close();

                                query = "select * from Albums"; //Query database for all albums
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                allAlbums.DataSource = reader; //Set query output as the table source
                                allAlbums.DataBind(); //Bind display table
                                reader.Close(); //Close reader

                                query = "select * from Albums as a where a.ownerID = " + num; //Query database for all albums
                                cmd = new MySqlCommand(query, cnn); //Create query command
                                reader = cmd.ExecuteReader(); //Execute query
                                myAlbums.DataSource = reader; //Set query output as the table source
                                myAlbums.DataBind(); //Bind display table
                                reader.Close(); //Close reader

                                updateOutput.Text = "Album successfully updated"; //Print success message
                                updateOutput.ForeColor = System.Drawing.Color.Green; //Make font green
                            }
                            else //Error case
                            {
                                updateOutput.Text = "Please enter the ID of an album you own."; //Print error message
                                updateOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                            }
                        }
                    }
                }
                else //Invalid input case
                {
                    updateOutput.Text = "Please enter the ID (integer number) of the album to delete."; //Print error message
                    updateOutput.ForeColor = System.Drawing.Color.Red; //Make font red
                }
            }
        }

        /*
         * This function navigates to the photos page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("PhotosView.aspx"); //Navigate to photos page
        }
    }
}