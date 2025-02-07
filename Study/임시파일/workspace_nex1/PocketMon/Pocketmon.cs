using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PocketMon
{
    internal class Pocketmon
    {
        protected string Name;
        protected int hp, lev, exp;
        
        public Pocketmon()
        {
            Name = "";
            hp = 0;
            lev = 0;
        }

        public Pocketmon(string name, int hp)
        {
            this.Name = name;
            this.hp = hp;
            this.lev = 1;
        }
        virtual public void Eat()
        {
            Console.WriteLine(Name + " Eatting");
        }
        virtual public void Sleep() 
        {
            Console.WriteLine(Name + " Sleep");
        }
        virtual public bool Excercise() 
        {
            Console.WriteLine(Name + " Excercise");
            return true;
        }
        virtual public bool Play()
        {
            Console.WriteLine(Name + " Play");
            return true;
        }
        virtual public void lvCheck()
        {
            Console.WriteLine(Name + " Level Check");
        }
        virtual public void printState()
        {
            Console.WriteLine(Name + " State");
            Console.WriteLine("hp:" + hp + "exp:" + exp + "lev:" + lev);
        }

    }

    class Pika : Pocketmon
    {
        public Pika() {
            Name = "Pika";
            hp = 30;
            exp = 0;
            lev = 1;
        }
        public Pika(string name, int hp) : base(name, hp) { }
        override public void Eat()
        {
            base.Eat();
            hp += 10;
        }
        override public void Sleep()
        {
            base.Sleep();
            hp += 20;
        }
        override public bool Excercise()
        {
            base.Excercise();
            hp -= 10;
            exp += 20;
            lvCheck();
            return hp > 0;
        }
        override public bool Play()
        {
            base.Play();
            hp -= 5;
            exp += 10;
            lvCheck();
            return hp > 0;
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 20*lev)
            {
                lev++;
                exp = 0;
                Console.WriteLine(Name + "Level UP : " + lev);
            }
        }
        public bool 백만볼트()
        {
            Console.WriteLine(Name + " 백만볼트");
            hp -= 20;
            return hp > 0;
        }
    }

    class Kobuk : Pocketmon
    {
        public Kobuk()
        {
            Name = "Kobuk";
            hp = 30;
            exp = 0;
            lev = 1;
        }
        public Kobuk(string name, int hp) : base(name, hp) { }
        override public void Eat()
        {
            base.Eat();
            hp += 5;
        }
        override public void Sleep()
        {
            base.Sleep();
            hp += 10;
        }
        override public bool Excercise()
        {
            base.Excercise();
            hp -= 2;
            exp += 20;
            lvCheck();
            return hp > 0;
        }
        override public bool Play()
        {
            base.Play();
            hp -= 1;
            exp += 10;
            lvCheck();
            return hp > 0;
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 30 * lev)
            {
                lev++;
                exp = 0;
                Console.WriteLine(Name + "Level UP : " + lev);
            }
        }
        public bool 물대포()
        {
            Console.WriteLine(Name + " 물대포");
            hp -= 20;
            return hp > 0;
        }
    }

    class Esan : Pocketmon
    {
        public Esan()
        {
            Name = "Esan";
            hp = 40;
            exp = 0;
            lev = 1;
        }
        public Esan(string name, int hp) : base(name, hp) { }
        override public void Eat()
        {
            base.Eat();
            hp += 15;
        }
        override public void Sleep()
        {
            base.Sleep();
            hp += 11;
        }
        override public bool Excercise()
        {
            base.Excercise();
            hp -= 12;
            exp += 30;
            lvCheck();
            return hp > 0;
        }
        override public bool Play()
        {
            base.Play();
            hp -= 11;
            exp += 20;
            lvCheck();
            return hp > 0;
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 25 * lev)
            {
                lev++;
                exp = 0;
                Console.WriteLine(Name + "Level UP : " + lev);
            }
        }
        public bool 넝쿨채찍()
        {
            Console.WriteLine(Name + " 넝쿨채찍");
            hp -= 20;
            return hp > 0;
        }
    }

    class UConsor
    {
        Pocketmon mypocketmon;
        public UConsor() { }

        private bool SelectPocketmon()
        {
            Console.WriteLine("Select the Your POCKETMON");
            Console.WriteLine("1.Pika 2.Kobuk 3. Esan");
            int num = Console.Read(); Console.Read();
            switch (num)
            {
                case '1':
                    mypocketmon = new Pika();
                    break;
                case '2':
                    mypocketmon = new Kobuk();
                    break;
                case '3':
                    mypocketmon = new Esan();
                    break;
                default:
                    Console.WriteLine("None");
                    return false;
            }
            return true;
        }

        private bool menu()
        {
            Console.WriteLine("Select what to do");
            Console.WriteLine("1.Sleep, 2.Eat, 3.Play, 4.Exercise 5.Attack");
            int num = Console.Read(); Console.Read();
            switch (num)
            {
                case '1':
                    mypocketmon.Sleep();
                    break;
                case '2':
                    mypocketmon.Eat();
                    break;
                case '3':
                    if (!mypocketmon.Play()) return false;
                    break;
                case '4':
                    if (!mypocketmon.Excercise()) return false;
                    break;
                case '5':
                    if (mypocketmon is Pika)
                    {
                        ((Pika)mypocketmon).백만볼트();
                    }
                    else if (mypocketmon is Kobuk)
                    {
                        ((Kobuk)mypocketmon).물대포();
                    }
                    else if (mypocketmon is Esan)
                    {
                        ((Esan)mypocketmon).넝쿨채찍();
                    }
                    break;
                default:
                    Console.WriteLine("None");
                    return false;
            }
            return true;

        }
        public void Run()
        {
            if (!SelectPocketmon()) return;
            
            while(true)
            {
                if(!menu()) break;
            }
        }
    }
}
