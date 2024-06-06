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
     * This interface defines the TempService service
     */
    [ServiceContract]
    public interface TempService
    {

        [OperationContract]
        int c2f(int c); //Celsius to Fahrenheit function

        [OperationContract]
        int f2c(int f); //Fahrenheit to Celsius function
    }
}
