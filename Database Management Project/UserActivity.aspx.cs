/*
 * Vincent Latona
 * Vyom Khare
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
    public partial class UserActivity : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the top 10 contributors into a table
         */
        protected void Page_Load(object sender, EventArgs e)
        {
            connectionString = @"Data Source=localhost;Initial Catalog=projectschema;User ID=root;Password=MySQLRoot"; //Initialize connection string
            cnn = new MySqlConnection(connectionString); //Initialize connection
            cnn.Open(); //Open connnection
            string query = "select u1.userID, u1.firstName, u1.lastName, ifnull(pCount,0)+ifnull(cCount,0) as score from" +
                "\r\nUsers as u1 left join\r\n(select distinct u.userID as id, ifnull(count(*),0) as cCount from Users as u, Comments as c" +
                "\r\nwhere c.ownerID = u.userID\r\ngroup by u.userID) as com\r\non com.id = u1.userID\r\nleft join\r\n" +
                "(select distinct u2.userID as id, ifnull(count(*),0) as pCount from Users as u2, Photos as p2, Albums as a2" +
                "\r\nwhere p2.albumID = a2.albumID and a2.ownerID = u2.userID\r\ngroup by u2.userID) as pho\r\non pho.id = u1.userID" +
                "\r\norder by score desc\r\nlimit 10;"; //Query database for top 10
            MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
            MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
            top10.DataSource = reader; //Set query result as source
            top10.DataBind(); //Bind the data
            reader.Close(); //Close reader
            cnn.Close(); //Close DB connection
        }

        /*
         * This function navigates to the friends pages
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("FriendSearch.aspx"); //Navigate to friends page
        }
    }
}
