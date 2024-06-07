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
     * This RESTful service wraps 2 easy services into a single service
     */
    [ServiceContract]
    public interface IService1
    {

        [OperationContract]
        [WebGet(UriTemplate = "StringWordCount?input={input}")] //RESTful Template
        int StringWordCount(string input); //Easy service 1 - Word Counter

        [OperationContract]
        [WebGet(UriTemplate = "CharacterCount?input={input}")] //RESTful Template
        int CharacterCount(string input); //Easy service 2 - Character Counter
    }
}
