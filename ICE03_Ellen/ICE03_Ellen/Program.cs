using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ICE03_Ellen
{
    class Program
    {
        static int[] randoms = new int[20];

        static void Main(string[] args)
        {
            // Write out fruit!
            string[] fruits = new string[5] { "mango", "orange", "apple", "banana", "dragonfruit" };
            foreach (string x in fruits)
            {
                Console.WriteLine(x);
            }

            Console.WriteLine();

            // Make random numbers!
            MakeRandoms();

            // Write out the random numbers!
            foreach (int x in randoms)
            {
                Console.Write("{0}", x);
            }

            Console.WriteLine();  // keep the program open
        }

        // Generate random numbers
        static void MakeRandoms()
        {
            Random ran = new Random();

            for (int i = 0; i < randoms.Length; i++)
            {
                randoms[i] = ran.Next(0, 100);
            }
        }
    }
}
