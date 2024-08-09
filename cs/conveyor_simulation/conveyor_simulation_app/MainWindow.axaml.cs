using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Avalonia.Threading;
using Avalonia.Markup.Xaml;
using System;

namespace ConveyorSimulation
{
    public partial class MainWindow : Window
    {
        private Rectangle _package;
        private Ellipse _sensor1;
        private Ellipse _sensor2;
        private Ellipse _led1;
        private Ellipse _led2;

        private double _packagePosition = 100;
        private double _conveyorSpeed = 2;

        public MainWindow()
        {
            InitializeComponent();
#if DEBUG
            this.AttachDevTools();
#endif
            _package = this.FindControl<Rectangle>("Package");
            _sensor1 = this.FindControl<Ellipse>("Sensor1");
            _sensor2 = this.FindControl<Ellipse>("Sensor2");
            _led1 = this.FindControl<Ellipse>("LED1");
            _led2 = this.FindControl<Ellipse>("LED2");

            // Timer do aktualizacji ruchu taśmociągu
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromMilliseconds(30);
            timer.Tick += OnTick;
            timer.Start();
        }

        private void OnTick(object sender, EventArgs e)
        {
            // Przesuń paczkę
            _packagePosition += _conveyorSpeed;

            // Jeśli paczka wychodzi poza ekran, resetuj pozycję
            if (_packagePosition > 750)
            {
                _packagePosition = 100;
            }

            // Aktualizacja pozycji paczki
            Canvas.SetLeft(_package, _packagePosition);

            // Sprawdzenie odległości do czujników i kontrola diod LED
            double sensor1Position = Canvas.GetLeft(_sensor1);
            double sensor2Position = Canvas.GetLeft(_sensor2);

            if (Math.Abs(_packagePosition + 25 - sensor1Position) < 50)
            {
                _led1.Fill = Brushes.Green;
            }
            else
            {
                _led1.Fill = Brushes.Red;
            }

            if (Math.Abs(_packagePosition + 25 - sensor2Position) < 50)
            {
                _led2.Fill = Brushes.Green;
            }
            else
            {
                _led2.Fill = Brushes.Red;
            }
        }

        private void InitializeComponent()
        {
            AvaloniaXamlLoader.Load(this);
        }
    }
}
