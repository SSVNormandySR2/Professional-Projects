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
    class OrderProcessor
    {
        /*
         * This function processes orders in the MultiCellBuffer
         */
        public void orderProcessing()
        {
            MainClass.processingAccess.WaitOne(); //Acquire processing access
            for(int a = 0; a < 2; a++) //Find order
            {
                MainClass.write.WaitOne(); //Acquire writer access
                OrderObject complete = MainClass.orders.getOneCell(a); //Read buffer cell
                if (complete != null) //Order found case
                {
                    MainClass.orders.setOneCell(a, null); //Overwrite buffer cell
                    MainClass.write.Release(); //Release writer access
                    int customerCard = complete.getCardNumber(); //Get card number
                    int customer = complete.getSenderId(); //Get sender ID
                    if(customerCard > 4999 & customerCard < 7001) //Valid card case
                    {
                        int locationCharge = 10; //Location charge
                        double taxCharge = 0.05; //Tax charge
                        if(customerCard < 6000) //Higher location and tax chare case
                        {
                            locationCharge = 20; //Modify location charge
                            taxCharge = 0.08; //Modify tax charge
                        }
                        int quantity = complete.getQuantity(); //Get quantity
                        double price = (1+taxCharge)*(complete.getUnitPrice() * quantity + locationCharge);
                        Console.WriteLine("Order Processed: \t Ticket Agency {0} order for {1} tickets for ${2} has been processed!",
                            customer, quantity, price.ToString("#.##")); //Print successful order
                    }
                    else //Invalid card case
                    {
                        Console.WriteLine("Order Canceled: \t Ticket Agency {0} order has invalid card number: {1}!",
                            customer, customerCard); //Print error message
                    }
                    break; //Finish processing
                }
                else //No order case
                {
                    MainClass.write.Release(); //Release writer access
                }
            }
            MainClass.agencyAccess.Release(); //Release agency access
        }
    }
}
