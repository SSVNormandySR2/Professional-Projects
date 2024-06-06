/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SortApp
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        /*
         * This function handles when the sort button is clicked
         */
        protected void sortButton_Click(object sender, EventArgs e)
        {
            Sorter.SortServiceClient sorter = new Sorter.SortServiceClient(); //Instance of service caller
            display.Text = sorter.sort(input.Text); //Call service and display output
        }
    }
}