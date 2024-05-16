import java.util.*;

class Triangle extends Exception {
    public String toString() {
        return "Not an acceptable triangle";
    }
}

public class ValidTriangle {
    public static void main(String args[]) throws Triangle {
        Scanner sc = new Scanner(System.in);
        int a, b, c;
        System.out.println("Enter the 3 sides of a triangle: ");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        try {
            if ((a < b + c) && (b < a + c) && (c < a + b)){
                System.out.println("Valid Triangle");
            }
            else{
                throw new Triangle();
            }
        }
        catch (Triangle e) {
            System.out.println(e);
        }
    }
}
