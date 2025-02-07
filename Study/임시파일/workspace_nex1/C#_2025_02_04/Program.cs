// See https://aka.ms/new-console-template for more information
using System.Collections;
using C__2025_02_04;

Console.WriteLine("Hello, World!");

ArrayList list = new ArrayList();
list.Add("asd");
list.Add(1);
list.Add(2.5);
list.Add(new Test());

foreach(object obj in list)
{
    Console.WriteLine(obj);
}
Console.WriteLine();

list.Insert(2, 90);
foreach (object obj in list)
{
    Console.WriteLine(obj);
}
Console.WriteLine();


Menu menu = new Menu();
menu.run();