package p1;

public class TwoDim {
    private int x;
    private int y;

    public TwoDim() {
        this.x = 0;
        this.y = 0;
    }

    public TwoDim(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public String toString() {
        return "Coordinate: x = " + x + " y = " + y;
    }
    
}