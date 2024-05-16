class A extends Thread{
    synchronized void displayTable(int n) {
        try {
            System.out.println("MULTIPLICATION TABLE FOR "+ n+ " IS: ");
            for (int i = 1; i <11; i++) {
                System.out.println(n+ " * " + i + " = "+ i * n);
                Thread.sleep(1000);
            }
        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}

class Mul extends Thread {
    A a;
    int n;

    Mul(A a, int n) {
        this.n = n;
        this.a = a;
    }

    public void run() {
        a.displayTable(n);
    }
}

public class ThreadMul {
    public static void main(String args[]) {
        A a = new A();
        Mul m = new Mul(a, 8);
        Mul m1 = new Mul(a, 9);
        m.start();
        m1.start();
    }
}