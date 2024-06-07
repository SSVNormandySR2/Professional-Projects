/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Drawing.Imaging;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace VLatonaAssignment8
{
    public partial class imageProcess : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Response.Clear(); //Clear response
            verifier.ServiceClient verifier = new verifier.ServiceClient(); //Create proxy
            string myStr, userLen; //Define strings for image service
            if (Session["generatedString"] == null) //First generated string case
            {
                if (Session["userLength"] == null) //First string case
                {
                    userLen = "3"; //Set default length to 3
                }
                else //User-defined length case
                {
                    userLen = Session["userLength"].ToString(); //Assign session value to local string
                }
                myStr = verifier.GetVerifierString(userLen); //Generate verifier string
                Session["generatedString"] = myStr; //Assign generated string to session
            }
            else //New request case
            {
                myStr = Session["generatedString"].ToString(); //Assign local string session value
            }
            Stream imageStream = verifier.GetImage(myStr); //Generate image
            System.Drawing.Image newImage = System.Drawing.Image.FromStream(imageStream); //Convert stream to image
            Response.ContentType = "image/jpeg"; //Set type to jpeg
            newImage.Save(Response.OutputStream, ImageFormat.Jpeg); //Send image
        }
    }
}