/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace XMLWebApp
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        /*
         * This function handles when the validation button is clicked
         */
        protected void validationButton_Click(object sender, EventArgs e)
        {
            if(xmlFileInput.Text != "" & xsdFileInput.Text != "") //Valid input case
            {
                string xmlFileUrl = xmlFileInput.Text; //Copy xml input
                string xsdFileUrl = xsdFileInput.Text; //Copy xsd input
                XMLServices.Service1Client xmlProxy = new XMLServices.Service1Client(); //Create service proxy
                validationOutput.Text = xmlProxy.validate(xsdFileUrl, xmlFileUrl); //Validate files
            }
            else //Empty input case
            {
                validationOutput.Text = "Please enter URLs of both .xml and .xsd files!"; //Print error message
            }
        }

        /*
         * This function handles when the search button is clicked
         */
        protected void searchButton_Click(object sender, EventArgs e)
        {
            if(searchXmlInput.Text != "" & searchNodeInput.Text != "") //Valid input case
            {
                string xmlFileUrl = searchXmlInput.Text; //Copy xml input
                string nodeName = searchNodeInput.Text; //Copy node name
                XMLServices.Service1Client xmlProxy = new XMLServices.Service1Client(); //Create service proxy
                searchOutput.Text = xmlProxy.search(xmlFileUrl, nodeName); //Search for node
            }
            else //Empty input case
            {
                searchOutput.Text = "Please enter an XML URL and/or an element/attribute to search!"; //Print error message
            }
        }
    }
}