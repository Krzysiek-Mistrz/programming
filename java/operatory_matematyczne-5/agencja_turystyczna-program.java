import java.util.Scanner;

public class Program
{
    public static void main(String[] args) 
    {
        Scanner Object = new Scanner(System.in);

        int distance = Object.nextInt();

        int kilometers = distance / 1000;
        int meters = distance % 1000;

        System.out.println(kilometers);
        System.out.println(meters);
    }
}
