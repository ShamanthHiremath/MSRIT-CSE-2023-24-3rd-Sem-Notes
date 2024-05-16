import java.awt.*;
import java.awt.event.*;

public class SimpleCalci extends Frame implements ActionListener {
    // Text fields and buttons
    TextField tf1, tf2, tf3;
    Button b1, b2, b3, b4;

    // Constructor
    SimpleCalci() {
        // Creating text fields
        tf1 = new TextField();
        tf1.setBounds(50, 50, 250, 20);

        tf2 = new TextField();
        tf2.setBounds(50, 100, 250, 20);

        // Creating result text field (read-only)
        tf3 = new TextField();
        tf3.setBounds(50, 150, 250, 20);
        tf3.setEditable(false);

        // Creating buttons
        b1 = new Button("+");
        b1.setBounds(50, 200, 50, 50);

        b2 = new Button("-");
        b2.setBounds(120, 200, 50, 50);

        b3 = new Button("*");
        b3.setBounds(190, 200, 50, 50);

        b4 = new Button("/");
        b4.setBounds(260, 200, 50, 50);

        // Adding action listeners to buttons
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);

        // Adding components to frame
        add(tf1);
        add(tf2);
        add(tf3);
        add(b1);
        add(b2);
        add(b3);
        add(b4);

        // Setting frame size, layout, and visibility
        setSize(360, 300);
        setLayout(null);
        setVisible(true);
    }

    // ActionListener method to handle button events
    public void actionPerformed(ActionEvent e) {
        String s1 = tf1.getText();
        String s2 = tf2.getText();
        int a = Integer.parseInt(s1);
        int b = Integer.parseInt(s2);
        int c = 0;

        if (e.getSource() == b1) {
            c = a + b;
        }
        else if (e.getSource() == b2) {
            c = a - b;
        }
        else if (e.getSource() == b3) {
            c = a * b;
        }
        else if (e.getSource() == b4) {
            if (b != 0) {
                c = a / b;
            }
            else {
                tf3.setText("Error: Division by zero");
                return;
            }
        }

        // Displaying result in tf3
        String result = String.valueOf(c);
        tf3.setText(result);
    }

    // Main method
    public static void main(String[] args) {
        new SimpleCalci();
    }
}
