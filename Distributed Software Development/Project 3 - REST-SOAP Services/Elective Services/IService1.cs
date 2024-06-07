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
     * This WSDL service wraps 2 easy services into a single service
     */
    [ServiceContract]
    public interface IService1
    {

        [OperationContract]
        int SpecialCharacterCount(string input); //Easy service 3 - Special Character Counter

        [OperationContract]
        int CountOccurrences(string input, char check); //Easy service 4 - Character Occurrence Counter
    }
}
