/*
 * Vincent Latona
 * Elective WSDL Counting Services
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace ElectiveWordServicesWSDL
{
    /*
     * This WSDL service implementation implements 2 individual services
     */
    public class Service1 : IService1
    {
        /*
         * This WSDL service counts the total number of special characters in a given input string
         */
        public int SpecialCharacterCount(string input)
        {
            int count = 0; //Initialize counting variable
            char[] specials = { '!', '@', '#', '$', '%', '^', 
                '&', '*', '(', ')', '-', '_', '=', '+', '/', 
                '|', '[', ']', '{', '}', '<', '>'}; //Define special characters
            foreach(char stringChar in input) //Iterate over string characters
            {
                foreach(char special in specials) //Iterate over special characters
                {
                    if(stringChar == special) //Special character case
                    {
                        count++; //Increment counter
                    }
                }    
            }
            return count; //Return final count
        }

        /*
         * This WSDL service counts the number of occurrences of a specific character within a given input string
         */
        public int CountOccurrences(string input, char check)
        {
            int count = 0; //Initialize counting variable
            foreach(char stringChar in input) //Iterate over string characters
            {
                if(stringChar == check) //Match case
                {
                    count++; //Increment counter
                }
            }
            return count; //Return final count
        }
    }
}
