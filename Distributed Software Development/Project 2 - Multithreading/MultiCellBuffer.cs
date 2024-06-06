/*
 * Vincent Latona
 * Individual Submission
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eCommerce
{
    public class MultiCellBuffer
    {
        private OrderObject[] cellBuffer; //Cell buffer

        /*
         * This constructor instantiates and initializes the cell buffer
         */
        public MultiCellBuffer()
        {
            cellBuffer = new OrderObject[2]; //Instantiate array
            for(int a = 0; a < 2; a++) //Initialize array
            {
                cellBuffer[a] = null; //Initialize as empty
            }
        }

        /*
         * This function writes a cell
         */
        public void setOneCell(int cellNum, OrderObject newOrder)
        {
            cellBuffer[cellNum] = newOrder; //Write buffer cell
        }

        /*
         * This function reads a cell
         */
        public OrderObject getOneCell(int cellNum)
        {
            return cellBuffer[cellNum]; ; //Return order
        }
    }
}
