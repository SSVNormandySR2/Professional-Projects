/*
 * Vyom Khare
 * Vincent Latona
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace HashLibrary
{
    public class Class1
    {
        //hashFunction
        public static string hashFunction(string plainText)
        {

            //using sha512
            using (SHA512 sha = SHA512.Create())
            {

                //compute has and return convert.ToHexString
                byte[] hashBytes = sha.ComputeHash(Encoding.UTF8.GetBytes(plainText));

                return BitConverter.ToString(hashBytes);
            }

        }   //end of hashFunction
    }
}
