#객체지향 

# 객체 비교
```C# folder title:compare
class Test {
	public int num;
	public Test(int num) {
		this.num = num;
	}
	public override bool Equals(object obj) {
		if (obj != null && obj is Test) {
			if (this.x == ((Test)obj).x)
				return true;
		}
		return false;
	}
}

Test t1 = new Test(1);
Test t2 = new Test(1);
Test t3 = t1;

Console.WriteLine("t1==t2:" + (t1 == t2));
Console.WriteLine("t1.Equals(t2):" + (t1.Equals(t2));
Console.WriteLine("t1==t3:" + (t1 == t3)); // 객체를 ==으로 배교하면 참조값 비교
// 객체의 내용을 비교하기 위해서는 Equals()를 재정의

string asd = "asdf"; // 상수의 주소 할당
string s1 = new string("aaa");
string s2 = new string("aaa");
string s3 = new string("bbb");
Console.WriteLine("s1 == s2 : " + (s1 == s2)); 
Console.WriteLine("s1 == s3 : " + (s1 == s3));
Console.WriteLine("s1.Equals(s2) : " + s1.Equals(s2)); // string은 이미 Equals가 재정의 되어 있음
```


# 추상 클래스
- abstract가 하나라도 있으면 추상 class
- 객체 생성 불가
- 상속 받아 모두 구현 해야지만 사용 가능
```C# folder title:추상클래스
abstract class PocketMon
{
	protected int hp, exp, lv;
	protected string name;
	public Pocketmon(string name, int hp)
	{
	     this.Name = name;
	     this.hp = hp;
	     this.lev = 1;
	}
	public abstract void Eat() { }
	public abstract void Sleep() { }
	public abstract bool Excercise()	{ }
	public abstract bool Play() { }
	public abstract void lvCheck() { }
	public abstract void printState() { }
}

```

# 인터페이스
- 완전 추상 클래스
- 객체 생성 불가
- 
```C# folder title:interface
namespace ConsorApp
{
	internal interface lanimal
	{
		void sound();
	}
	class Dog : lanimal
	{
		public void sound() 
		{
			Console.WriteLine("멍멍멍");
		}
	}
	class Cat : lanimal
	{
		public void sound() 
		{
			Console.WriteLine("애애옴");
		}
	}
	class Action() 
	{
		public boid action(lanimal animal) // 인터페이스 활용
		{
			animal.sound();
		}
	}
}
```