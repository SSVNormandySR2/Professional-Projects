/*
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
    public partial class TopTags : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the top tags table
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection 
            cnn.Open(); //Open connection

            loadTable(); //Populate table
        }

        /*
         * This function loads the top tags table with retrieved values
         */
        private void loadTable()
        {
            string query = "select t.tag, count(*) as photos\r\nfrom Tags as t" +
                "\r\ngroup by t.tag\r\norder by photos desc"; //Query database for top tags
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            topTags.DataSource = reader; //Set query output as the table source
            topTags.DataBind(); //Bind display table
            reader.Close(); //Close reader
        }

        /*
         * This function navigates to the tag search page
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            cnn.Close(); //Close DB connection
            Response.Redirect("TagSearch.aspx"); //Navigate to tag search
        }
    }
}
