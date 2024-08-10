using Avalonia.Controls;
using Avalonia.Media.Imaging;
using Avalonia.Threading;
using System;
using System.Threading;

namespace tasmociag.Views;

public partial class MainWindow : Window
{
    private DispatcherTimer _timer = new DispatcherTimer();
    private double _paczka_pos;
    private const double _end_pos = 800;

    public MainWindow() {
        InitializeComponent();
        start_animation();
    }

    private void start_animation() {
        _paczka_pos = Canvas.GetLeft(paczka);
        _timer = new DispatcherTimer { Interval = TimeSpan.FromMilliseconds(50) };
        _timer.Tick += on_timer_tick;
        _timer.Start();
    }

    private void on_timer_tick(object? sender, EventArgs e) {
        _paczka_pos += 5;
        if(_paczka_pos >= _end_pos)
            _timer.Stop();
        else
            Canvas.SetLeft(paczka, _paczka_pos);
        if(_paczka_pos >= 300 && _paczka_pos < 350)
            led1.Source = LoadBitmap("Assets/led_on.png");
        else if(_paczka_pos >= 600 && _paczka_pos < 650)
            led2.Source = LoadBitmap("Assets/led_on.png");
    }

    private Bitmap? LoadBitmap(string uri) {
            try {
                var bitmap = new Bitmap(uri);
                return bitmap;
            } catch (Exception ex) {
                Console.WriteLine($"Error loading image: {ex.Message}");
                return null;
            }
    }
}