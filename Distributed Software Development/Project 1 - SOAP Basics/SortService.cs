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
     * This interface defines the SortService service
     */
    [ServiceContract]
    public interface SortService
    {

        [OperationContract]
        string sort(string s); //Integer sorting function
    }
}
