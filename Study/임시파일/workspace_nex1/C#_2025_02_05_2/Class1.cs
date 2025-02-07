using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_05_2
{
    internal class Class1
    {
        public static void KeyRead()
        {
            for (int i = 0; i < 5; i++)
            {
                string str = Console.ReadLine();
                Console.WriteLine("input : " + str);
            }
        }

        public static void FileRead()
        {
            string path = "C:\\workspace_nex1\\C#_2025_02_05_2\\a.txt.txt";

            StreamReader sr = new StreamReader(path);
            string str = null;
            while ((str = sr.ReadLine()) != null)
            {
                Console.WriteLine("file : " + str);
                Thread.Sleep(1000);
            }
            sr.Close();
        }

        public static void Main(string[] args) {
            Thread th1 = new Thread(KeyRead);
            th1.Start();

            Thread th2 = new Thread(FileRead);
            th2.Start();

        }

    }
}
