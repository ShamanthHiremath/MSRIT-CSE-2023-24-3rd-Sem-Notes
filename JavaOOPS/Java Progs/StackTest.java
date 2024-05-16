interface stackop {
    void push(int item);

    int pop();
    void displayStack();
}

class FixedStack implements stackop {
    private int stk[];
    private int top;
    private int size;

    FixedStack(int size) {
        stk = new int[size];
        this.size=size;
        top = -1;
    }

    public void push(int item) {
        if (top == size-1) {
            System.out.println("Stack Overflows");
            return ;
        }
        else
            stk[++top] = item;
    }

    public int pop() {
        if (top < 0) {
            System.out.println("Stack Underflows");
            return 0;
        }
        else
            return stk[top--];
    }
    public void displayStack(){
        int i=this.top;
        System.out.println("ELEMENTS OF THE STACK ARE: ");
        while(i>-1){
            System.out.println(stk[i--]);
        }
    }
}

class DynStack implements stackop {
    private int stk[];
    private int top;

    DynStack(int size) {
        stk = new int[size];
        top = -1;
    }

    public void push(int item) {
        if (top == stk.length - 1) {
            System.out.println("Stack Overflows");
            System.out.println("RESIZING STACK");
            int t[] = new int[stk.length * 2];
            for (int i = 0; i < stk.length; i++)
                t[i] = stk[i];
            stk = t;
            stk[++top] = item;
        } else
            stk[++top] = item;
    }

    public int pop() {
        if (top < 0) {
            System.out.println("Stack Underflows.");
            return 0;
        } else
            return stk[top--];
    }

    public void displayStack(){
        int i=this.top;
        System.out.println("ELEMENTS OF THE STACK ARE: ");
        while(i>-1){
            System.out.println(stk[i--]);
        }
    }
}

class StackTest {
    public static void main(String args[]) {
        FixedStack fs = new FixedStack(3);
        DynStack ds = new DynStack(5);
        stackop mystk;
        for (int i = 0; i < 3; i++)
            fs.push(i);
        System.out.println("Fixed length Stack Contents are.");
        for (int i = 0; i < 3; i++)
            System.out.println(fs.pop());
        for (int i = 0; i < 7; i++)
            ds.push(i);
        System.out.println("Dynamic length Stack Contents are");
        for (int i = 0; i < 7; i++)
            System.out.println(ds.pop());
        mystk = fs;
        for (int i = 0; i < 3; i++)
            mystk.push(i);
        System.out.println("Fixed length Stack Contents using interface reference");
        mystk.displayStack();
        mystk = ds;
        for (int i = 0; i < 7; i++)
            mystk.push(i);
        System.out.println("Dynamic length Stack Contents using interface reference");
        for (int i = 0; i < 7; i++)
            System.out.println(mystk.pop());
    }
}