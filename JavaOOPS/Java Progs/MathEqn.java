class MathSin extends Thread {
    double deg;
    double result;

    public MathSin(double degree) {
        deg = degree;
    }

    public void run() {
        result = Math.sin(deg);
    }
}

class MathCos extends Thread {
    double deg;
    double result;

    public MathCos(double degree) {
        deg = degree;
    }

    public void run() {
        result = Math.cos(deg);
    }
}

class MathTan extends Thread {
    double deg;
    double result;

    public MathTan(double degree) {
        deg = degree;
    }

    public void run() {
        result = Math.tan(deg);
    }
}

public class MathEqn {
    public static void main(String[] args) {
        double totalAdd;
        MathSin sin = new MathSin(45.0);
        MathCos cos = new MathCos(45.0);
        MathTan tan = new MathTan(45.0);
        sin.start();
        cos.start();
        tan.start();
        try {
            sin.join();
            cos.join();
            tan.join();
            totalAdd = sin.result + cos.result + tan.result;
            System.out.println("sin(x) + cos(x) + tan(x): " + totalAdd);
        }
        catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }
    }
}
