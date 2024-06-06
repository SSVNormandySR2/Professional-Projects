/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TempApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /*
         * This function handles when the Fahrenheit conversion button is pressed
         */
        private void cToF_Click(object sender, EventArgs e)
        {
            Temp.TempServiceClient converter = new Temp.TempServiceClient(); //Instance of service caller
            int fahrenheit = converter.c2f(int.Parse(tempInput.Text)); //Call service
            tempDisplay.Text = fahrenheit.ToString() + " degrees Fahrenheit"; //Display output
        }

        /*
         * This function handles when the Celsius conversion button is pressed
         */
        private void fToC_Click(object sender, EventArgs e)
        {
            Temp.TempServiceClient converter = new Temp.TempServiceClient(); //Instance of service caller
            int celsius = converter.f2c(int.Parse(tempInput.Text)); //Call service
            tempDisplay.Text = celsius.ToString() + " degrees Celsius"; //Display output
        }
    }
}
