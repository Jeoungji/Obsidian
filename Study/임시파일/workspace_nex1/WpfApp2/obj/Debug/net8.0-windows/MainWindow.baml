   M S B A M L   `   `   `  ����B  >WpfApp2, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:WpfApp2WpfApp2  5   	       WpfApp2.MainWindow   5   	   W SPresentationCore, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=8.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=8.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   'localclr-namespace:WpfApp2     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)    � DataContext$# ViewModel.MainWindowViewModel��5	   	   .��5
      � .+�5   
   �� $
��Left=�6-   $��	31,20,0,0q�6H    �� TextWrapping$
 Wrap=�6[   $	��Top=�6o   $	��120��6�   $��32��6�   ��6   �� *	Model.Num+6�   �� 5   
   $
��Left=�6.   $��	31,57,0,0q�6I   $
 Wrap=�6\   $	��Top=�6p   $	��120��6�   $��32��6�   ��6   �� *
Model.Name+6�   �� 5   
   $
��Left=�6/   $��	31,94,0,0q�6J   $
��Wrap=�6]   $	��Top=�6q   $	��120��6�   $��32��6�   ��6   �� *	Model.Res+6�   �� 5   
   $��
text input��6)   $
��Left=�6>   $��
31,126,0,0q�6Y   $	��Top=�6m   $	��120��6�   $��32��6�   ��6   �� *Cmd+6�   �� 5   
   $��184,19,443,276q�6t    �� SelectedItem 6   �� *p+ �� SelectedIndex 6-   �� *SelectedIdx+��6T   �� *	Persons+��5      �� 5      .R�5      � $	��0,2q�6    � ColumnDefinitions 5      �� 5      $��50 �6/   �� 5      .+�5      �� ��6$   �� *Num+�� 5      $��1��6$   ��64   �� *Name+5      5      5      �� 5   
   $
��Save��6-   $
��Left=�6<   $��
31,163,0,0q�6W   $	��Top=�6k   $	��120��6�   $��20��6�   ��6   �� *	SaveCmd+6�   �� 5   
   $
��Edit��6-   $
��Left=�6<   $��184,163,0,0q�6W   $	��Top=�6l   $	��163��6�   ��6   �� *	EditCmd+6�   �� 5   
   $��Delete��6/   $
��Left=�6@   $��184,183,0,0q�6[   $	��Top=�6p   $	��163��6�   ��6   �� *	DeleteCmd+6�   5"      5#      