// See https://aka.ms/new-console-template for more information
using C__2025_02_04_1;

Console.WriteLine("Hello, World!");


// static 멤버는 객체 생성과 상관없이 사용가능
// static 멤버는 객체 이름이 아닌 클래스 이름으로 접근
Console.WriteLine("객체 생성 전 static a:" + StaticTest.a);

// 객체 생성시 멤버변수 자동초기화
// 숫자 타입:0, 객체 타입 null
StaticTest st = new StaticTest(); //힙에 객체 생성, 객체에는 b만 생성됨 b=0
StaticTest.a++;
st.b++;
Console.WriteLine("a:" + StaticTest.a + ". b:" + st.b);

StaticTest.a++; //static 멤버는 모든 객체가 공유, 새로 만들어지지 않음
st.b++;
Console.WriteLine("a:" + StaticTest.a + ". b:" + st.b);


Console.WriteLine("프로그램 시작");
int x = 3, y = 0;
ExceptionTest obj = null;
int[] arr = { 1, 2, 3 };
Console.WriteLine("짝수를 입력");
int num = Int32.Parse(Console.ReadLine());
try
{
    Console.WriteLine("예외 발생 전");
    //Console.WriteLine("3/0 : " + (x / y));
    //obj.x = 10;
    // for (int i = 0; i < arr.Length + 1; i++) Console.WriteLine(arr[i]);

    if (num % 2 == 1)
    {
        throw new MyException("짝수여야");
    }
    Console.WriteLine("예외 발생 후");
}
catch (DivideByZeroException e) // 예외 종류가 같아야 처리 가능
{
    Console.WriteLine(e.ToString());
}
catch (NullReferenceException e)
{
    Console.WriteLine(e.ToString());
}
catch (Exception e) // 모든 exception처리, 위에 부터 비교하므로 가장 아래에 배치
{
    Console.WriteLine(e.ToString());
}
finally
{
    Console.WriteLine("Finally");
}

Console.WriteLine("프로그램 종료");