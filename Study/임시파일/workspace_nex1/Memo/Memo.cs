using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEMO
{
    internal class Memo
    {
        private string dir;
        private string filename;
        public Memo() {
            dir = "";
            filename = "";
        }
        public Memo(string dir)
        {
            this.dir = dir;
            this.filename = "";
        }

        public void PrintDirFile(string dir)
        {
            try
            {
                DirectoryInfo Dir = new DirectoryInfo(dir);
                FileInfo[] files = Dir.GetFiles();
                Console.WriteLine(dir);
                Console.WriteLine("--------------------------");
                int i = 1;
                foreach (FileInfo file in files)
                {
                    Console.WriteLine(i++ + " : " + file.Name);
                }
                Console.WriteLine("--------------------------");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message.ToString());
            }
        }
        public void PrintDirFile()
        {
            PrintDirFile(dir);
        }

        public string SetFilename()
        {

            return filename;
        }
    }
}
