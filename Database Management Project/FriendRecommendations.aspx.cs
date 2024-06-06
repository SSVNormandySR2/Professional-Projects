/*
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
    public partial class FriendRecommendations : System.Web.UI.Page
    {
        private string connectionString = ""; //DB connection string
        private MySqlConnection cnn; //DB connection

        /*
         * This function loads the recommended friends into a table
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
                    string query = "select f.followedID, u.firstName, u.lastName, count(*) as commonFriends " +
                        "\r\nfrom Users as u, Friends as f\r\nwhere u.userID = f.followedID " +
                        "and f.followerID in\r\n(select f1.followedID from Friends as f1\r\nwhere f1.followerID = " + num + ") and " +
                        "f.followedID not in\r\n(select f2.followedID from Friends as f2\r\nwhere f2.followerID = " + num + ")" +
                        "\r\nand f.followedID != " + num + "\r\ngroup by f.followedID\r\norder by commonFriends desc;"; //Query database for recommended friends
                    MySqlCommand cmd = new MySqlCommand(query, cnn); //Create query command
                    MySqlDataReader reader = cmd.ExecuteReader(); //Execute query
                    dispTable.DataSource = reader; //Set query output as the table source
                    dispTable.DataBind(); //Bind display table
                    reader.Close(); //Close reader
                }
            }
            cnn.Close(); //Close DB connection
        }

        /*
         * This function handles navigation to the albums pages
         */
        protected void navButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("AlbumView.aspx"); //Navigate to albums pages
        }
    }
}
