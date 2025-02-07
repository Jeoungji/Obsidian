using System.Printing;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1_2025_02_06_1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<string>list = new List<string>();
        List<Person> list2;
        public MainWindow()
        {
            InitializeComponent();
            list.Add("abc");
            list.Add("cba");
            lst1.ItemsSource = list;

            list2 = new List<Person>();
            list2.Add(new Person("asaad", 102));
            list2.Add(new Person("asaad", 101));
            lst2.ItemsSource = list2;
        }

        private void btn1_Click(object sender, RoutedEventArgs e)
        {
            Button btn = (Button)sender;
            MessageBox.Show(btn.Content.ToString());
        }

        private void save_Click(object sender, RoutedEventArgs e)
        {
            txt.Text = input.Text;
            input.Text = "";
        }

        private void personEdit_Click(object sender, RoutedEventArgs e)
        {

        }

        private void personDel_Click(object sender, RoutedEventArgs e)
        {

        }

        
    }


    public class Person
    {
        public string Name { get; set; }
        public int Id { get; set; }

        public Person() { }
        public Person(string name, int id)
        {
            Name = name;
            Id = id;
        }

        public override string ToString()
        {
            return "Name : " + Name + " ID : " + Id;
        }
    }

}