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
    public class OrderObject
    {
        private int senderId; //Sending thread ID
        private int cardNumber; //Sending thread card number
        private int quantity; //Number of tickets requested
        private double unitPrice; //Price of tickets

        /*
         * This function sets the Sender ID field
         */
        public void setSenderId(int Id)
        {
            senderId = Id; //Set sender ID
        }

        /*
         * This function sets the Card Number field
         */
        public void setCardNumber(int card)
        {
            cardNumber = card; //Set card number
        }

        /*
         * This function sets the Quantity field
         */
        public void setQuantity(int q)
        {
            quantity = q; //Set quantity
        }

        /*
         * This function sets the Unit Price field
         */
        public void setUnitPrice(double price)
        {
            unitPrice = price; //Set unit price
        }

        /*
         * This function gets the Sender ID field value
         */
        public int getSenderId()
        {
            return senderId; //Return sender ID value
        }

        /*
         * This function gets the Card Number field value
         */
        public int getCardNumber()
        {
            return cardNumber; //Return card number value
        }

        /*
         * This function gets the Quantity field value
         */
        public int getQuantity()
        {
            return quantity; //Return quantity value
        }

        /*
         * This function gets the Unit Price field value
         */
        public double getUnitPrice()
        {
            return unitPrice; //Return unit price value
        }
    }
}
