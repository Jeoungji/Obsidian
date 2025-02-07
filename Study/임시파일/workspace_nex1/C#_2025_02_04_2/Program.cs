// See https://aka.ms/new-console-template for more information
using C__2025_02_04_2;
using System.Collections;

Console.WriteLine("\n해쉬 example");

Hashtable hashtable = new Hashtable();
hashtable.Add("name", "aaa");
hashtable.Add("tel", "111");
hashtable.Add("addr", "대한민국");

Console.WriteLine(hashtable["name"]);
Console.WriteLine(hashtable["tel"]);
Console.WriteLine(hashtable["addr"]);

foreach(string key in hashtable.Keys)
{
    Console.WriteLine(key +" : " + hashtable[key]);
}
Console.WriteLine();

foreach (string val in hashtable.Values)
{
    Console.WriteLine(val);
}
Console.WriteLine();

hashtable.Remove("name");
foreach (string key in hashtable.Keys)
{
    Console.WriteLine(key + " : " + hashtable[key]);
}
Console.WriteLine();

hashtable.Clear();
foreach (string key in hashtable.Keys)
{
    Console.WriteLine(key + " : " + hashtable[key]);
}
Console.WriteLine();


Console.WriteLine("\n큐 example");

Queue q = new Queue();
q.Enqueue(1);
q.Enqueue("10");
q.Enqueue(q);


Console.WriteLine("\n배열 example");
Myarr<int> arr1 = new Myarr<int>(4);
try
{
    for (int i = 0; i < 5; ++i)
    {
        arr1.Add(i);
        Console.WriteLine("count : " + arr1.Count);
        Console.WriteLine("size : " + arr1.Size);
    }
}
catch(Exception e)
{
    Console.WriteLine(e.ToString());
}

arr1.PrintAll();

try
{
    Console.WriteLine("2번방 : " + arr1.get(2));
    Console.WriteLine("20번방 : " + arr1.get(20));
}
catch (Exception e)
{
    Console.WriteLine(e.ToString());
}


Myarr<NamedValue<string, string>> arr3 = new Myarr<NamedValue<string, string>>(3);

arr3.Add(new NamedValue<string, string>("name", "abc"));
arr3.Add(new NamedValue<string, string>("tel", "111"));


arr3.PrintAll();

Console.WriteLine("1번방:" + arr3.get(1));


Console.WriteLine("\n리스트 example");
List<string> list = new List<string>();
list.Add("aaa");
list.Add("bbb");

foreach (string s in list) { Console.WriteLine(s); }
Console.WriteLine("1번방 : " + list[1]);
Console.WriteLine("aaa의 위치 : " + list.IndexOf("aaa"));
list.Remove("bbb");
foreach(string item in list) { Console.WriteLine(item); }
list.Clear();
Console.WriteLine("list 요소수:" + list.Count);

Console.WriteLine("\n딕셔너리 example");

Dictionary<string, string> dic = new Dictionary<string, string>();
dic.Add("key1", "val1");
dic.Add("key2", "val2");
foreach(KeyValuePair<string, string> s in dic) { Console.WriteLine(s); }
dic["key3"] = "val3";
dic["key2"] = "new val2";
foreach (KeyValuePair<string, string> s in dic) { Console.WriteLine(s); }

Console.WriteLine("dic[key1 : " + dic["key1"]);
dic.Remove("key1");
foreach (KeyValuePair<string, string> s in dic) { Console.WriteLine(s); }


Console.WriteLine("\nstream example");

string fname = "C:\\workspace_nex1\\C#_2025_02_04_2\\a.txt";

StreamWriter sw = new(fname);

sw.WriteLine("aaa");
sw.WriteLine("가나다라 마바사");
sw.WriteLine("홀리몰리");
sw.Close();

StreamReader sr = new(fname);
string str = "";
while((str = sr.ReadLine()) != null)
{
    Console.WriteLine(str);
}
sr.Close();

StreamReader copyreader = new(fname);
string copyname = "C:\\workspace_nex1\\C#_2025_02_04_2\\copy.txt";
StreamWriter copycopy = new(copyname);
while ((str = copyreader.ReadLine()) != null)
{
    copycopy.WriteLine(str);
}
copyreader.Close();
copycopy.Close();

StreamReader copycopyreader = new(copyname);
while ((str = copycopyreader.ReadLine()) != null)
{
    Console.WriteLine(str);
}

Console.WriteLine("\nFile example");

string filename = "C:\\workspace_nex1\\C#_2025_02_04_2\\data\\file.txt";
if (!File.Exists(filename))
{
    File.Create(filename);
    Console.WriteLine("파일 생성됨");
}

File.WriteAllText(filename, "c 파일 내용");
//Console.WriteLine(File.ReadAllText(filename));

DirectoryInfo dir = new DirectoryInfo("C:\\workspace_nex1\\C#_2025_02_04_2\\data");
FileInfo[]files = dir.GetFiles();
foreach (FileInfo file in files)
{
    Console.WriteLine(file.FullName);
}

File.Delete(filename);

files = dir.GetFiles();
foreach (FileInfo file in files)
{
    Console.WriteLine(file.FullName);
}