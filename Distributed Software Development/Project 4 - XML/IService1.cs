/*
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace XMLServices
{
    /*
     * This service defines operations on XML files
     */
    [ServiceContract]
    public interface IService1
    {

        [OperationContract]
        string validate(string xsdFileUrl, string xmlFileUrl); //2.1 - XML Verification operation

        [OperationContract]
        string search(string xmlFileUrl, string nodeName); //2.2 - XML Search operation
    }

    /*
     * Class for validation error handling
     */
    [DataContract]
    public class Errors
    {
        bool errorOccurred = false; //Boolean for error state
        List<string> errors = new List<string>(); //List for error messages

        /*
         * This function defines accessor/mutators for error state
         */
        [DataMember]
        public bool ErrorOccurred
        {
            get { return errorOccurred; } //Error state accessor
            set { errorOccurred = value; } //Error state mutator
        }

        /*
         * This function defines accessor/mutators for list of error messages
         */
        [DataMember]
        public string GetErrors
        {
            set { errors.Add(value); } //List mutator
            get //List accessor
            {
                string errorList = ""; //String to return
                foreach(string error in errors) //Iterate over error messages
                {
                    errorList += error; //Concatenate messages
                }
                return errorList; //Return list of messages
            }
        }
    }
}
