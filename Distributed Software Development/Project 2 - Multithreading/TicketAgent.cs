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
    public class TicketAgent
    {
        private int id; //Thread ID for orders
        private int creditCard; //Credit card number for orders
        private double currentPrice; //Current price of tickets
        private double need; //Need for new tickets
        private Random rand; //RNG for need and card generation

        /*
         * This constructor instantiates a ticket agent
         */
        public TicketAgent(int senderId)
        {
            rand = new Random(); //Initialize RNG
            id = senderId; //Set initial ID
            creditCard = rand.Next(5000, 7000); //Generate card number
            currentPrice = 160.00; //Set initial price to $160
            need = 0.5; //Set initial need to 50%
        }

        /*
         * This function executes the agency functionality
         */
        public void agentFunction()
        {
            Cruise cruise = new Cruise(); //Create local cruise for price generation
            while (true)
            {
                Thread.Sleep(300); //Sleep for 300 ms
                currentPrice = cruise.getCurrentPrice(); //Get current price
                need = rand.NextDouble(); //Determine ticket needs
                Console.WriteLine("Agency Advertisement: \t Ticket Agency {0} has tickets for as low as ${1}!",
                    id, currentPrice.ToString("#.##")); //Print newest ticket prices
                lock (MainClass.cruiseFinished) //Lock boolean access
                {
                    if(MainClass.cruiseFinished.Equals(true)) //Cruise Line finished case
                    {
                        break; //Stop thread execution
                    }
                }
            }
        }

        /*
         * This callback function will decide how many tickets to order and places an order into the MultiCellBuffer
         */
        public void priceDrop(double lowerPrice)
        {
            double priceDifference = (currentPrice - lowerPrice); //Calculate price difference
            OrderObject newOrder = new OrderObject(); //Create new order
            if (need > 0.5 & priceDifference > 1) //High need case
            {
                newOrder.setSenderId(id); //Set sender field
                newOrder.setCardNumber(creditCard); //Set card field
                newOrder.setUnitPrice(lowerPrice); //Set price field
                if(need > 0.7) //High price difference case
                {
                    int quantity = (int)(rand.Next(2, 4) * priceDifference); //Request 2 times more tickets
                    newOrder.setQuantity(quantity); //Set quantity field
                }
                else //Low price difference case
                {
                    int quantity = (int)(priceDifference); //Request 2 times more tickets
                    newOrder.setQuantity(quantity); //Set quantity field
                }
                need = 0; //Reset need
                MainClass.agencyAccess.WaitOne(); //Acquire agency access
                for (int a = 0; a < 2; a++) //Find open cell
                {
                    MainClass.write.WaitOne(); //Acquire writer access
                    if (MainClass.orders.getOneCell(a) == null) //Open buffer cell case
                    {
                        MainClass.orders.setOneCell(a, newOrder); //Place order
                        MainClass.write.Release(); //Release writer access
                        break; //Exit search loop
                    }
                    else //Occupied buffer cell case
                    {
                        MainClass.write.Release(); //Release writer access
                    }
                }
                MainClass.processingAccess.Release(); //Release processor access
                Console.WriteLine("Order Confirmation: \t Ticket Agency {0} has placed an order for {1} tickets.",
                    newOrder.getSenderId(), newOrder.getQuantity()); //Print order report
                OrderProcessor order = new OrderProcessor(); //Create new processor object for thread
                Thread processor = new Thread(new ThreadStart(order.orderProcessing)); //Create order processor thread
                processor.Start(); //Start order processor thread
            }
        }
    }
}
