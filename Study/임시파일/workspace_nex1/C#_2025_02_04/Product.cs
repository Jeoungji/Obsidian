using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C__2025_02_04
{
    internal class Product
    {
        private static int cnt;
        public int id {  get; set; }
        public string name { get; set; }
        public int price { get; set; }
        public int amount { get; set; }

        public Product() { }

        public Product(string name, int price, int quantity)
        {
            this.name = name;
            this.price = price;
            this.amount = quantity;
            this.id = cnt++;
        }

        public override string ToString()
        {
            return "id:" + id + "  name:" + name + "  price:" + price + "  amount:" + amount;
        }
        public override bool Equals(object? obj)
        {
            if (obj != null && obj is Product)
            {
                Product p = (Product)obj;
                if (id == p.id && name == p.name) return true; // 번호와 이름까지 같은 객체
            }
            return false;
        }
    }

    internal class ProductManager
    {
        private ArrayList list;
        public ProductManager()
        {
            this.list = new ArrayList();
        }

        public void insert(Product npro)
        {
            list.Add(npro);
        }

        public Product Select(Product p)
        {
            int idx = list.IndexOf(p);
            if (idx < 0)
            {
                return null;
            }
            return (Product)list[idx];
        }

        public void delete(Product p)
        {
            try
            {
                list.Remove(p);
            }
            catch (NotSupportedException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public void selectAll()
        {
            foreach(Product p in list)
            {
                Console.WriteLine(p);
            }
        }
    }

    internal class ProductService
    {
        private ProductManager manager;
        public ProductService() { manager = new ProductManager(); }

        public void addProd()
        {
            Console.WriteLine("제품등록");
            Console.Write("제품명: ");
            string name = Console.ReadLine();
            Console.Write("가격: ");
            int price = Int32.Parse(Console.ReadLine());
            Console.Write("수량: ");
            int amount = Int32.Parse(Console.ReadLine());
            manager.insert(new Product(name, price, amount));
        }

        private Product getProdInfo(string str)
        {
            Console.WriteLine(str);
            Product p = new Product();
            Console.Write(str+"할 제품명: ");
            p.name = Console.ReadLine();
            Console.Write(str+"할 제품 번호: ");
            p.id = Int32.Parse(Console.ReadLine());
            return p;
        }
        public void getProd()
        {
            Console.WriteLine("검색");
            Product p = new Product();
            Console.Write("검색할 제품명: ");
            p.name = Console.ReadLine();
            Console.Write("검색할 제품 번호: ");
            p.id = Int32.Parse(Console.ReadLine());
            Product p2 = manager.Select(p);
            if (p2 != null)
            {
                Console.WriteLine(p2);
            }
            else
            {
                Console.WriteLine("not found");
            }
        }

        public void updateProd()
        {
            Console.WriteLine("수정");
            Product p = new Product();
            Console.Write("수정할 제품명: ");
            p.name = Console.ReadLine();
            Console.Write("수정할 제품 번호: ");
            p.id = Int32.Parse(Console.ReadLine());
            Product p2 = manager.Select(p);
            if (p2 != null)
            {
                Console.WriteLine("수정 전 상품정보");
                Console.WriteLine(p2);
                Console.Write("새 가격: ");
                p2.price = Int32.Parse(Console.ReadLine());
                Console.Write("새 수량: ");
                p2.amount = Int32.Parse(Console.ReadLine());
            }
            else
            {
                Console.WriteLine("not found");
            }
        }

        public void delProb()
        {
            Console.WriteLine("삭제");
            Product p = new Product();
            Console.Write("삭제할 제품명: ");
            p.name = Console.ReadLine();
            Console.Write("삭제할 제품 번호: ");
            p.id = Int32.Parse(Console.ReadLine());
            this.manager.delete(p);
        }

        public void PrintAll()
        {
            manager.selectAll();
        }
    }

    internal class Menu
    {
        private ProductService service;

        public Menu() { service = new ProductService(); }

        public void run()
        {
            int m;
            while (true) {
                Console.WriteLine("1.추가 2.검색 3.수정 4.삭제 5.전체 출력 6.종료");
                m = Int32.Parse(Console.ReadLine());
                switch (m) {
                case 1:
                    service.addProd();
                    break;
                case 2:
                    service.getProd();
                    break;
                case 3:
                    service.updateProd();
                    break;
                case 4:
                    service.delProb();
                    break;
                case 5:
                    service.PrintAll();
                    break;
                case 6:
                    return;            
                }
            }
        }

    }
}
