/*
 * Vincent Latona
 * Services implemented: Services 4 and 2
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using System.Web;
using System.Web.UI.WebControls;

namespace WordServices
{
    /*
     * This service combines the services of WordCount and Word Filer
     */
    [ServiceContract]
    public interface IService1
    {

        [OperationContract]
        string WordCount(string[] lines); //This operation defines the WordCount service (service 4)

        [OperationContract]
        string WordFilter(string str); //This operation defines the WordFilter service (service 2)
    }
}
