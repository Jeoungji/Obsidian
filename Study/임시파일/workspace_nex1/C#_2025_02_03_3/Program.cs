// See https://aka.ms/new-console-template for more information
using C__2025_02_03_3;

Console.WriteLine("Hello, World!");

Parent parent = new Parent("a", "d", 10);

Child child = new Child("a", "ds", 5, "adv");

parent.Method();
parent.vmethod();

child.Method();
child.vmethod();

Parent p2 = child; // 업캐스팅
p2.Method();
p2.vmethod();

((Child)p2).Hobby = "golila";
p2.vmethod();