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

namespace SortService
{
    /*
     * This class implements the SortService functions
     */
    public class Service1 : SortService
    {
        /*
         * This function sorts a given set of integers
         */
        public string sort(string s)
        {
            string sorted = "";
            List<int> toBeSorted = new List<int>(); //List for integer sorting
            string[] subs = s.Split(','); //Parse input string
            foreach(string element in subs) //Conversion iterator
            {
                toBeSorted.Add(int.Parse(element)); //Convert and add to list
            }
            toBeSorted.Sort(); //Sort the list
            foreach(int element in toBeSorted) //String conversion
            {
                sorted = sorted + element + " "; //Concatenate string
            }
            return sorted; //Return sorted list
        }
    }
}
