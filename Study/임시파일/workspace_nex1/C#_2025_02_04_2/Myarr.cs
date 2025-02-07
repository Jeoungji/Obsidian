using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_04_2
{
    internal class Myarr<T>
    {
        private T[] arr;
        public int Count { get; set; } // 요소의 개수
        public int Size { set; get; } // 방의 개수

        public Myarr(int size)
        {
            this.Size = size;
            arr = new T[this.Size];
        }

        public void Add(T item)
        {
            if (Count == Size)
            {
                throw new Exception("배열 참");
            }
            arr[Count++] = item;
        }

        public T get(int idx)
        {
            if (idx < 0 || idx > Count)
            {
                throw new Exception("잘못된 인덱스");
            }
            return arr[idx];
        }

        public void PrintAll()
        {
            foreach (T item in arr)
            {
                Console.WriteLine(item);
            }

        }
    }
    class NamedValue<T, V>
    {
        public T Name { set; get; }
        public V Value { set; get; }

        public NamedValue(T name, V value)
        {
            Name = name; Value = value;
        }

        public override string ToString()
        {
            return "Name:" + Name + " Value:" + Value;
        }
    }
}
