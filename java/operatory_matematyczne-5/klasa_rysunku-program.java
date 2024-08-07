import java.util.Scanner;

public class Program 
{
    public static void main(String[] args)
    {
        Scanner Object = new Scanner(System.in);
        int pupils = Object.nextInt();
        int pencils = Object.nextInt();

        int howMuch = pencils * pupils;
        System.out.println("How much pencils: " + howMuch);
    }
}