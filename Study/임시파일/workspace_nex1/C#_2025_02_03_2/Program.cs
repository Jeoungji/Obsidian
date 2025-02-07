// See https://aka.ms/new-console-template for more information
using C__2025_02_03_2;

Console.WriteLine("Hello, World!");

Person p1 = new Person("aaa", 15);

p1.printInfo();

p1.Name = "gor";
p1.Age = 10;

p1.printInfo();
Console.WriteLine(p1); // == ToString()
Console.WriteLine(p1.ToString());
Console.WriteLine(p1.GetHashCode());
// C#의 모든 클래스는 Object class를 상속


object[] obj = { 1, 1.5, "aaa", new Test(1) };

foreach(object o in obj)
{
    if (o is Test)
    {
        Console.WriteLine("x:" + ((Test)o).num);
    }
    else
    {
        Console.WriteLine(o);
    }
}