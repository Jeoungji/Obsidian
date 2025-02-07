using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_04_1
{
    internal class StaticTest
    {
        public static int a;
        public int b;

        // 일반 메소드, 객체 생성 후 호출 가능
        // 일반 멤버 변수, static 변수 접근 가능
        public void test1()
        {
            a = 1;
            b = 2;
        }

        // static 메서도는 객체 생성전에도 호출 가능
        // 객체 생성 전엔 일반 멤버 생성전이라 사용 불가능
        public static void test2()
        {
            a = 1;
        }

        public void test3()
        {
            test1(); // 일반 메소드
            test2(); // static 메소드
        }

        public static void test4()
        {
            // test1(); // 객체 생성 전 일반 메소드 사용 불가
            test2(); // static 메소드
        }
    }
}
