using System;
using System.Diagnostics;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace simple_calc_improved.Views;

public partial class MainWindow : Window
{
    private double sum = 0;
    private double difference = 0;
    private double product = 0;
    private double quotient = 0;
    public MainWindow()
    {
        InitializeComponent();
    }

    public void button_add_Click(object sender, RoutedEventArgs args)
    {
        //Debug.WriteLine($"first num val: {first_num.Text}");
        //Debug.WriteLine($"second num val: {second_num.Text}");
        if (Double.TryParse(first_num.Text, out double first) && Double.TryParse(second_num.Text, out double second))
        {
            sum = first + second;
            output.Text = sum.ToString("0.0");
        }
        else
        {
            output.Text = "Invalid input";
        }
    }

    public void button_subtract_Click(object sender, RoutedEventArgs args)
    {
        if (Double.TryParse(first_num.Text, out double first) && Double.TryParse(second_num.Text, out double second))
        {
            difference = first - second;
            output.Text = difference.ToString("0.0");
        }
        else
        {
            output.Text = "Invalid input";
        }
    }

    public void button_multiply_Click(object sender, RoutedEventArgs args)
    {
        if (Double.TryParse(first_num.Text, out double first) && Double.TryParse(second_num.Text, out double second))
        {
            product = first * second;
            output.Text = product.ToString("0.0");
        }
        else
        {
            output.Text = "Invalid input";
        }
    }

    public void button_divide_Click(object sender, RoutedEventArgs args)
    {
        if (Double.TryParse(first_num.Text, out double first) && Double.TryParse(second_num.Text, out double second))
        {
            if (second != 0)
            {
                quotient = first / second;
                output.Text = quotient.ToString("0.0");
            }
            else
            {
                output.Text = "Cannot divide by zero";
            }
        }
        else
        {
            output.Text = "Invalid input";
        }
    }
}
