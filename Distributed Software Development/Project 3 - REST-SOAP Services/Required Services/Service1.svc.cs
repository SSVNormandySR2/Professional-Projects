/*
 * Vincent Latona
 * Services implemented: Services 4 and 2
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WordServices
{
    public class Service1 : IService1
    {
        /*
         * This operation implements the WordCount service by counting individual words of a file (service 4)
         */
        public string WordCount(string[] lines)
        {
            string dictionary = ""; //Initialize return dictionary
            string[] symbolsToRemove = { ".", ",", ":", ";", "!", "{", "}", "[", "]"}; //Define symbols to remove
            for(int a = 0; a < lines.Length; a++) //Iterate over all lines
            {
                foreach(string symbol in symbolsToRemove) //Iterate over all symbols
                {
                    lines[a] = lines[a].Replace(symbol, ""); //Remove the given symbol from each line
                }
            }
            Dictionary<string, int> counter = new Dictionary<string, int>(); //Create word counter
            foreach (string line in lines)
            {
                string[] words = line.Split(' '); //Split line into individual words
                foreach(string word in words)
                {
                    if(counter.TryGetValue(word, out int count)) //Repeated word case
                    {
                        counter[word] = count + 1; //Increase count
                    }
                    else //New word case
                    {
                        counter.Add(word, 1); //Add new word to dictionary
                    }
                }
            }
            foreach(KeyValuePair<string, int> pair in counter) //Build return string
            {
                dictionary = dictionary + "(" + pair.Key + ", " + pair.Value.ToString() + ")\n"; //Convert pair to string
            }
            return dictionary; //Return dictionary of unique words and count
        }

        /*
         * This operation implements the WordFilter service by removing stop words of a string (service 2)
         */
        public string WordFilter(string str)
        {
            string modified = str; //Copy the input string
            string[] symbolsToRemove = { ".", ",", ":", ";", "!", "{", "}", "[", "]" }; //Define symbols to remove
            string[] wordsToRemove = 
                {" a ", " an ", " in ", " on ", " the ", " is ", " are ", 
                " am ", " another ", " for ", " nor ", " but ", " yet ", 
                " so ", " or ", " under ", " towards ", " before ", 
                " through ", " against ", " without ", " from ", " at ", 
                " with ", " since ", " after ", " of ", " to "}; //Define stop words to remove
            modified = modified.ToLower(); //Convert text to lowercase
            foreach (string symbol in symbolsToRemove) //Remove symbols
            {
                modified = modified.Replace(symbol, ""); //Replace given symbol
            }
            foreach (string word in wordsToRemove) //Remove stop words
            {
                modified = modified.Replace(word, " "); //Replace given stop word
            }
            return modified; //Return fully modified string
        }
    }
}
