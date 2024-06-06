/*
 * Vincent Latona
 * Individual Submission
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace eCommerce
{
    public class Cruise
    {
        public static event priceCutEvent priceCut; //Price cut event
        private int cuts = 20; //Max number of price cuts
        private static double currentPrice = 160.00; //Current price starts at $160.00
        private Random rand = new Random(); //RNG for price model

        /*
         * This function returns the current price
         */
        public double getCurrentPrice()
        {
            return currentPrice; //Return current price
        }

        /*
         * This function generates new prices between $40 and $200
         */
        private void priceModel()
        {
            int r1 = rand.Next(40, 200); //Generate operator 1
            int r2 = rand.Next(40, 200); //Generate operator 2
            double newPrice = Math.Sqrt(r1 * r2); //Generate new price from operators
            if(newPrice < currentPrice) //Price drop case
            {
                Console.WriteLine("Price Drop: \t Cruise Company {0} tickets are now on sale: ${1} per ticket!",
                    Thread.CurrentThread.Name, newPrice.ToString("#.##")); //Print new price
                if (priceCut != null) //Subscribers case
                {
                    priceCut(newPrice); //Emit event
                }
                cuts--; //Decrement remaining price cuts
            }
            currentPrice = newPrice; //Set new price
        }

        /*
         * This function executes the cruise functionality
         */
        public void cruiseFunction()
        {
            while(cuts > 0) //Run until 20 price cuts have occurred
            {
                Thread.Sleep(200); //Sleep for 200 ms
                priceModel(); //Generate new price
                Console.WriteLine("Cruise Advertisement:  \t Cruise Company {0} has prices as low as ${1} per ticket!", 
                    Thread.CurrentThread.Name, currentPrice.ToString("#.##")); //Print current price
            }
            lock(MainClass.cruiseFinished) //Lock boolean access
            {
                MainClass.cruiseFinished = true; //Set boolean to true
            }
        }
    }
}
