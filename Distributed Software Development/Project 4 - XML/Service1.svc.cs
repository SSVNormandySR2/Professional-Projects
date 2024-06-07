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
using System.Xml;
using System.Xml.Schema;
using System.IO;
using System.EnterpriseServices;
using System.Web.UI.WebControls.WebParts;

namespace XMLServices
{
    /*
     * This service implements operations on given XML files
     */
    public class Service1 : IService1
    {
        private Errors errors = new Errors(); //Define private error-tracking object

        /*
         * This function performs XML validation of a given XML file against its XSD file
         */
        public string validate(string xsdFileUrl, string xmlFileUrl)
        {
            string validation = "No Error"; //Define message to return
            XmlSchemaSet schemas = new XmlSchemaSet(); //Define set of schemas
            schemas.Add(null, xsdFileUrl); //Add validation schema to set
            XmlReaderSettings settings = new XmlReaderSettings(); //Define reader settings
            settings.ValidationType = ValidationType.Schema; //Set schema validation
            settings.Schemas = schemas; //Associate schema with settings
            settings.ValidationEventHandler += new ValidationEventHandler(ValidationCallBack); //Set event handler
            XmlReader validationReader = XmlReader.Create(xmlFileUrl, settings); //Crate validation reader
            while(validationReader.Read()); //Validate the file
            if (errors.ErrorOccurred)
            {
                validation = errors.GetErrors; //Get error messages
            }
            return validation; //Return validation message
        }

        /*
         * This function is an error handler for the validation function
         */
        private void ValidationCallBack(object sender, ValidationEventArgs e)
        {
            errors.ErrorOccurred = true; //Set error state
            errors.GetErrors = "Validation Error: " + e.Message + "\n"; //Add error message
        }

        /*
         * This function performs a search on an XML document using DOM
         */
        public string search(string xmlFileUrl, string nodeName)
        {
            XmlDocument document = new XmlDocument(); //Define DOM object
            document.Load(xmlFileUrl); //Load XML file into memory
            XmlNode root = document.DocumentElement; //Get root node
            string results = nodeIterate(root, nodeName); //Conduct search
            if(results == "") //Not found case
            {
                results = "Search node could not be found."; //Set return message
            }
            return results; //Return result message
        }

        /*
         * This function performs the search on the DOM object
         */
        private string nodeIterate(XmlNode parent, string searchName)
        {
            string result = ""; //Initialize search result message
            if (parent == null) //Empty node case
            {
            }
            else
            {
                if (parent.Attributes != null) //Search attributes case
                {

                    if(parent.Attributes.Count > 0)
                    {
                        foreach (XmlAttribute att in parent.Attributes) //Iterate over attributes
                        {
                            if (att.Name == searchName) //Attribute case
                            {
                                result = result + "Attribute: " + searchName
                                    + " value: " + att.Value + " found in " + parent.Name + "\n\n"; //Add attribute result
                                return result; //Return found attribute
                            }
                        }
                    }
                }
                if (parent.Name == searchName) //Node case
                {
                    result = result + "Element: " + searchName + "\n"; //Add element result
                    if (parent.Attributes != null) //Add attributes case
                    {
                        if(parent.Attributes.Count > 0)
                        {
                            result = result + searchName + " attribute(s): \n"; //Attribute header
                            foreach (XmlAttribute att in parent.Attributes) //Iterate over attributes
                            {
                                result = result + "Attribute: " + att.Name
                                    + " value: " + att.Value + "\n"; //Add attribute result
                            }
                        }
                    }
                    if (parent.HasChildNodes) //Add children case
                    {
                        result = result + searchName + " value(s): \n"; //Children header
                        foreach (XmlNode child in parent.ChildNodes) //Iterate over children
                        {
                            result = result + foundChildren(child); //Add child results to parent results
                        }
                    }
                    result = result + "\n";
                }
                else if (parent.HasChildNodes) //Search children case
                {
                    foreach (XmlNode child in parent.ChildNodes) //Iterate over children
                    {
                        result = result + nodeIterate(child, searchName); //Add child results to parent results
                    }
                }
            }
            return result; //Return search results
        }

        /*
         * This function prints all children of a found node
         */
        private string foundChildren(XmlNode child)
        {
            string childResult = ""; //Initialize search result message
            if(child == null) //Empty node case
            {
            }
            else //Non-empty case
            {
                if(child.NodeType.ToString() == "Element") //Element case
                {
                    childResult = childResult + "Element: " + child.Name + "\n";
                    if (child.Attributes != null) //Add attributes case
                    {
                        if(child.Attributes.Count > 0)
                        {
                            childResult = childResult + child.Name + " attribute(s): \n"; //Attribute header
                            foreach (XmlAttribute att in child.Attributes) //Iterate over attributes
                            {
                                childResult = childResult + "Attribute: " + att.Name
                                    + " value: " + att.Value + "\n"; //Add attribute result
                            }
                        }
                    }
                    if (child.HasChildNodes) //Children case
                    {
                        childResult = childResult + child.Name + " value(s): \n"; //Children header
                        foreach (XmlNode grandChild in child.ChildNodes) //Iterate over children
                        {
                            childResult = childResult + foundChildren(grandChild); //Add child results to parent results
                        }
                    }
                }
                else //Text case
                {
                    childResult = childResult + "Text value: " + child.Value + "\n"; //Add text value result
                } 
            }
            return childResult; //Return child results
        }
    }
}
