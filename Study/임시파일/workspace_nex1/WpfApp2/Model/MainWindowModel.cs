using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Printing;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp2.Model
{
    public class MainWindowModel : INotifyPropertyChanged
    {
        private int num = 1;
        public int Num
        {
            get { return num; }
            set { num = value; onPropertyChanged("Num"); }
        }

        private string name = "aaa";
        public string Name
        {
            get { return name; }
            set { name = value; onPropertyChanged("Name"); }
        }

        private string res;
        public string Res
        {
            get { return res; }
            set { res = value; onPropertyChanged("Res"); }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected void onPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null) handler(this, new PropertyChangedEventArgs(propertyName));
        }
    }

    public class Person : INotifyPropertyChanged
    {
        private int num;
        public int Num
        {
            get { return num; }
            set { num = value; onPropertyChanged("Num"); }
        }
        private string name;
        public string Name
        {
            get { return name; }
            set { name = value; onPropertyChanged("Name"); }
        }
        public Person(int num, string name)
        {
            this.num = num;
            this.name = name;
        }

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void onPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null) handler(this, new PropertyChangedEventArgs(propertyName));
        }

        public override string ToString()
        {
            return num + " / " + name;
        }
    }
}
