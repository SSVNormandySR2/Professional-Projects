/*
 * Vincent Latona
 * Individual Submission
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading;

namespace eCommerce
{
    public delegate void priceCutEvent(double price);
    public class MainClass
    {
        public static Semaphore write = new Semaphore(1, 1); //Semaphore for write access to a MultiCellBuffer cell
        public static Semaphore agencyAccess = new Semaphore(2, 2); //Semaphore for ticket agency access to the MultiCellBuffer
        public static Semaphore processingAccess = new Semaphore(0, 2); //Semaphore for order processor access to the MultiCellBuffer
        public static Object cruiseFinished = false; //Event for agency synchronization
        public static MultiCellBuffer orders = new MultiCellBuffer(); //MultiCellBuffer for orders

        /*
         * This function runs the program
         */
        public static void Main()
        {
            int agencyNum = 5; //Number of ticket agency threads to run
            Cruise cruiseCompany = new Cruise(); //Create cruise object for thread creation
            Thread cruiseThread = new Thread(new ThreadStart(cruiseCompany.cruiseFunction)); //Set cruise thread function
            cruiseThread.Name = "0"; //Name the cruise company
            cruiseThread.Start(); //Start cruise thread
            for(int a = 0; a < agencyNum; a++) //Create and start agency threads
            {
                TicketAgent ticketAgency = new TicketAgent(a); //Create ticket agency object for thread creation
                Cruise.priceCut += new priceCutEvent(ticketAgency.priceDrop); //Subscribe agency to event
                Thread agent = new Thread(new ThreadStart(ticketAgency.agentFunction)); //Set agency thread function
                agent.Name = (a).ToString(); //Name agent thread
                agent.Start(); //Start agency thread
            }
        }
    }
}