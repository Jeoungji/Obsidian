using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_03_2
{
    internal class Person
    {
        string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public int Age
        {
            get;set;
        }

        public Person()
        {
            name = "";
            Age = 0;
        }
        public Person(string name, int age)
        {
            this.name = name;
            this.Age = age;
        }

        public void printInfo()
        {
            Console.WriteLine("name : " + name + "  age : " + Age);
        }

        public override string ToString() // Object로 받은 ToString을 재정의
        {
            // base는 부모
            //return base.ToString();

            return "name:" + name + " age:" + Age;
        }
    }

    class Test
    {
        public int num;
        public Test(int num)
        {
            this.num = num;
        }
    }
}
