import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class LambdaEventListenerExample extends JFrame {
    JTextField tf;
    JButton b;

    LambdaEventListenerExample(){
        tf = new JTextField("CLICK ON THE BUTTON");
        tf.setBounds(50, 50, 150, 20);
        b = new JButton("BUTTON");
        b.setBounds(80, 100, 70, 30);

        // lambda expression implementing here.
        b.addActionListener(e -> {
            tf.setText("HI SWING");
        });

        // JFrame f = new JFrame();
        add(tf);
        add(b);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setSize(300, 200);
        setVisible(true);

    }
        
    public static void main(String[] args) {
        new LambdaEventListenerExample();

    }
}