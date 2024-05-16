import java.io.*;

public class ExceptionKeywords {
    public static void main(String[] args) {
        try {
            // Example of try block
            int result = 10/0; // This will throw an ArithmeticException
        } catch (ArithmeticException e) {
            // Example of catch block
            System.out.println("ArithmeticException caught: " + e.getMessage());
        } finally {
            // Example of finally block
            System.out.println("Finally block executed");
        }

        try {
            // Example of throw keyword
            throw new IOException("Custom IOException");
        } catch (IOException e) {
            // Example of catch block for custom exception
            System.out.println("IOException caught: " + e.getMessage());
        }

        try {
            // Example of throws keyword
            readFile("nonexistentfile.txt");
        } catch (FileNotFoundException e) {
            // Example of catch block for checked exception
            System.out.println("FileNotFoundException caught: " + e.getMessage());
        }
    }

    // Example method that throws an ArithmeticException
    public static int divide(int dividend, int divisor) {
        return dividend / divisor;
    }

    // Example method that throws a checked exception
    public static void readFile(String filename) throws FileNotFoundException {
        FileReader fr = new FileReader(filename);
    }
}
