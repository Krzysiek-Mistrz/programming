using System;
using System.Diagnostics;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace simple_calc.Views;

public partial class MainWindow : Window
{
    private double sum = 0;
    public MainWindow()
    {
        InitializeComponent();
    }

    public void button_clicked(object source, RoutedEventArgs args){
        Debug.WriteLine($"first num val: {first_num.Text}");
        Debug.WriteLine($"second num val: {second_num.Text}");
        if(Double.TryParse(first_num.Text, out double first) && Double.TryParse(second_num.Text, out double second)) {
            sum = first + second;
            //or if sum of type int-> Convert.ToInt32(first_num.Text) + Convert.ToInt32(second_num.Text)
            output.Text = sum.ToString("0.0");
        }
        else {
            sum = 0;
            first_num.Text = "0";
            second_num.Text = "0";
        }
    }
}