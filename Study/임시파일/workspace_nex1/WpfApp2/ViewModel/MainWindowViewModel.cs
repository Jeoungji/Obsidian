using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfApp2.Model;

namespace WpfApp2.ViewModel
{
    public class MainWindowViewModel : INotifyPropertyChanged
    {
        public int SelectedIdx { get; set; }
        public Person p { get; set; }

        private ObservableCollection<Person> persons;

        public ObservableCollection<Person> Persons
        {
            get { return persons;}
        }

        private MainWindowModel model;
        public MainWindowModel Model 
        {
            get { return model; }
            set { model = value; onPropertyChanged("Model"); }
        }
        public Command Cmd { get; set; }
        public Command SaveCmd { get; set; }
        public Command EditCmd { get; set; }
        public Command DeleteCmd { get; set; }

        public MainWindowViewModel()
        {
            model = new MainWindowModel();
            Cmd = new Command(execute, canExecute);
            SaveCmd = new Command(saveexecute, canExecute);
            EditCmd = new Command(editexecute, canExecute);
            DeleteCmd = new Command(deleteexecute, canExecute);
            persons = new ObservableCollection<Person>();
            persons.Add(new Person(1, "aaa"));
            persons.Add(new Person(2, "bbb"));
            
        }

        private void execute(object obj)
        {
            Model.Res = Model.Num + " / " + Model.Name;
        }

        private void editexecute(object obj)
        {
            MessageBox.Show(p.ToString() + "  idx:" + SelectedIdx);
            persons[SelectedIdx].Num = Model.Num;
            persons[SelectedIdx].Name = Model.Name;
        }
        private void saveexecute(object obj)
        {
            persons.Add( new Person(Model.Num, Model.Name));
            onPropertyChanged("Persons");
        }
        private void deleteexecute(object obj)
        {
            MessageBox.Show(p.ToString() + "  idx:" + SelectedIdx);
            persons.RemoveAt(SelectedIdx);
            onPropertyChanged("Persons");
        }

        private bool canExecute(object obj)
        {
            return true;
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected void onPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null) handler(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
