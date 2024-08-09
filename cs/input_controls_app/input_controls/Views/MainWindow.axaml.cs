using System.Diagnostics;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace input_controls.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    public void ButtonClicked(object source, RoutedEventArgs args)
    {
        Debug.WriteLine("Click!");
    }
}