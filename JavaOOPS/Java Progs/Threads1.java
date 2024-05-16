class A extends Thread {
    public void run() {
        int i = 0;
        while (i < 3) {
            System.out.println(2*i+1);
            i++;
        }
        try {
            wait();
        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}

class B extends Thread {
    int n;

    B(int n) {
        this.n = n;
    }

    public void reverse(int n){
        int reversed = 0;
        while (n != 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }
        System.out.println("Reversed Number: " + reversed);
    }

    public void run() {
        reverse(n);
    }
}

public class Threads1 {
    public static void main(String[] args) {
        A a = new A();
        B b = new B(1234);
        a.start();
        b.start();
    }
}