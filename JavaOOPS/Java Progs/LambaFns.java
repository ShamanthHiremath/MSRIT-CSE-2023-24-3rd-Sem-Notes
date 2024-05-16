// Functional interface to represent calculator operations
interface Calc {
    int res(int x, int y); // Single abstract method
}

public class LambaFns {
    public static void main(String args[]) {
        // Lambda expression for addition operation
        Calc addition = (x, y) -> (x + y);
        System.out.println("SUM IS: " + addition.res(2, 3));

        // Lambda expression for multiplication operation
        Calc multiplication = (x, y) -> (x * y);
        System.out.println("PRODUCT IS: " + multiplication.res(3, 4));
    }
}

