using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_03_3
{
    internal class Parent
    {
        public string Nickname { get; set; }
        protected string name = "";
        protected int age = 0;

        public Parent() { }
        public Parent(string nickname, string name, int age)
        {
            Nickname = nickname;
            this.age = age;
            this.name = name;
        }

        public void Method()
        {
            Console.WriteLine("Parent : nickname:" + Nickname + " name:" + name + " age:" + age);
        }

        public virtual void vmethod()
        {
            Console.WriteLine("Parent : virtual");
            Console.WriteLine("         nickname:" + Nickname + " name:" + name + " age:" + age);
        }
    }

    internal class Child : Parent
    {
        public string Hobby { get; set; }
        public Child() { }
        public Child(string nickname, string name, int age, string hobby)
            : base(nickname, name, age) {
            Hobby = hobby;
        }

        new public void Method() // new로 상속받은 method 재정의 , 현재 자료형을 따라감
        {
            Console.WriteLine("Child : new function");
            Console.WriteLine("        nickname:" + Nickname + " name:" + name + " age:" + age + " hobby:" + Hobby);
        }

        override public void vmethod() // 원래 자료형을 따라감
        {
            Console.WriteLine("Child : override function");
            Console.WriteLine("        nickname:" + Nickname + " name:" + name + " age:" + age + " hobby:" + Hobby);
        }
    }

}
