using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_03
{
    class Car
    {
        public string model;
        public int door;
        public string color;

        public Car()
        {
            model = "기본차";
            door = 3;
            color = "감장";
        }
        public Car(string model, int door, string color)
        {
            this.model = model;
            this.door = door;
            this.color = color;
        }
        public void printInfo()
        {
            Console.WriteLine("mode : " + model + "  door : " + door
                                + "  color : " + color);
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Car car1 = new Car();
            car1.printInfo();

            Car car2 = new Car("Second", 4, "Red");
            car2.printInfo();

            int[] arr = { 1, 2, 3 }; // 초기화 생성, 0으로 초기화
            int[] arr2 = new int[5]; // 지정한 크기 생성
            int i;
            for (i = 0; i < arr2.Length; i++)
            {
                Console.Write(arr2[i] + "\t");
            }
            Console.WriteLine();
            for (i = 0; i < arr2.Length; i++)
            {
                arr2[i] = i + 1;
            }

            for (i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + "\t");
            }
            Console.WriteLine();
            for (i = 0; i < arr2.Length; i++)
            {
                Console.Write(arr2[i] + "\t");
            }
            Console.WriteLine();

            string[] str = { "abc", "cbs" };
            for (i = 0; i < str.Length; i++)
            {
                Console.Write(str[i] + "\t");
            }
            Console.WriteLine();

            Car[] cars = new Car[3]; // 객체 포인터 방만 만듦
            cars[0] = new Car("gogo", 4, "sh");
            cars[1] = new Car("mo", 1, "q");
            cars[2] = new Car();

            for (i = 0; i < cars.Length; i++)
            {
                cars[i].printInfo();
            }
            Console.WriteLine();
        }
    }
}
