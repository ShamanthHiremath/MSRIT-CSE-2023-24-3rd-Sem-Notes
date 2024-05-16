import java.util.*;

class Name extends Exception {
    String name;

    Name(String n) {
        name = n;
    }

    public String toString() {
        return name + " is not an acceptable name";
    }
}

class Age extends Exception {
    int age;

    Age(int a) {
        age = a;
    }

    public String toString() {
        return age + " is greater than 50";
    }
}

class Employee {
    int a;
    String n;

    Employee(int a, String n) {
        this.a = a;
        this.n = n;
    }

    void display() {
        System.out.println("Employee Name:" + n + "\nEmployee age:" + a);
    }
}

public class Main {
    public static void main(String args[]) throws Age, Name {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name and age");
        int a, h;
        String n;
        boolean b = true;
        n = sc.next();
        a = sc.nextInt();
        try {
            h = Integer.parseInt(n);
            b = false;
            throw new Name(n);
        }
        catch (Name e) {
            System.out.println(e);
        }
        catch (Exception e) {
        }
        try {
            if (a > 50) {
                b = false;
                throw new Age(a);
            }
        }
        catch (Age e) {
            System.out.println(e);
        }
        if (b == true) {
            Employee e = new Employee(a, n);
            e.display();
        }
    }
}
