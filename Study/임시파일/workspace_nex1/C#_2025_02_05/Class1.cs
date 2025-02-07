using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_05
{
    internal class Class1
    {
        public static void Test()
        {
            for (int i = 0; i < 30; i++)
            {
                Console.WriteLine(i);
                Thread.Sleep(500);
            }
        }
        public static void Test2(object name)
        {
            for (int i = 0; i < 30; i++)
            {
                Console.WriteLine((string)name + ":" + i);
                Thread.Sleep(500);
            }
        }
        public static void Main(string[] args)
        {
            Thread thread = new Thread(Test);
            thread.Start();

            Thread t1 = new Thread(new ParameterizedThreadStart(Test2));
            t1.Start("test2");

            for (int i = 'a'; i <= 'z'; i++)
            {
                Console.WriteLine((char)i);
                Thread.Sleep(500);
            }
        }
    }
}
