/*
 * Vincent Latona
 * Elective RESTful Counting Services
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace ElectiveWordServices
{
    /*
     * This RESTful service implementation implements 2 individual easy services
     */
    public class Service1 : IService1
    {
        /*
         * This RESTful service counts the number of words in a given input string
         */
        public int StringWordCount(string input)
        {
            int wordCount = 0; //Initialize count to 0
            string[] words = input.Split(' '); //Split string into words
            wordCount = words.Length; //Get number of words
            return wordCount; //Return total word count
        }

        /*
         * This RESTful service counts the number of characters in a given input string
         */
        public int CharacterCount(string input)
        {
            int characterCount = 0; //Initialize count to 0
            foreach(char stringChar in input) //Iterate over characters in the string
            {
                characterCount++; //Increment character count
            }
            return characterCount; //Return total character count
        }
    }
}
