/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace TempService
{
    /*
     * This class implements the TempService functions
     */
    public class Service1 : TempService
    {
        /*
         * This function converts Celsius integers to Fahrenheit integers
         */
        public int c2f(int c)
        {
            return c * 9 / 5 + 32; //Return conversion
        }

        /*
         * This function converts Fahrenheit integers to Celsius integers
         */
        public int f2c(int f)
        {
            return (f - 32) * 5 / 9; //Return conversion
        }
    }
}
