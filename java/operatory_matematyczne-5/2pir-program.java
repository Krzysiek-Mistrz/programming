import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner Rad = new Scanner(System.in);
        
        double radius = Rad.nextDouble();
        double pi = 3.14;
        double perimeter = 2 * pi * radius;
        
        System.out.println(perimeter);
    }
}