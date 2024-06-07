using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Optimization;
using System.Web.Routing;
using System.Web.Security;
using System.Web.SessionState;

namespace VLatonaAssignment8
{
    public class Global : HttpApplication
    {
        void Application_Start(object sender, EventArgs e)
        {
            // Code that runs on application startup
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);
            Application["SessionCounter"] = 0; //Initialize session counter
        }

        /*
         * This event handler increments the session count
         */
        void Session_Start(object sender, EventArgs e)
        {
            lock (this) //Synchronize the object
            {
                int count = (int)Application["SessionCounter"]; //Get the current session count
                count++; //Increment count
                Application["SessionCounter"] = count; //Set new count
            }
        }

        /*
         * This event handler decrements the session count
         */
        void Session_End(object sender, EventArgs e)
        {
            lock (this) //Synchronize the object
            {
                int count = (int)Application["SessionCounter"]; //Get the current session count
                count--; //Decrement count
                Application["SessionCounter"] = count; //Set new count
            }
        }
    }
}