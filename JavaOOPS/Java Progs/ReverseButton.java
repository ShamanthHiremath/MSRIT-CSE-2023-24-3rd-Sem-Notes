import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ReverseButton extends JFrame implements ActionListener {
    private JButton b;
    private JTextField t, t1;

    public ReverseButton() {
        setTitle("Reverse App");
        setSize(300, 150);
        setLayout(new FlowLayout()); // Set the layout manager
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("Enter a Number:");
        add(label);

        t = new JTextField(15);
        add(t);

        b = new JButton("Reverse");
        b.addActionListener(this);
        add(b);

        t1 = new JTextField(15);
        t1.setEditable(false); // Make it read-only
        add(t1);

        setVisible(true); // Make the frame visible
    }

    public void actionPerformed(ActionEvent e) {
        String input = t.getText();
        String reversed = new StringBuilder(input).reverse().toString();
        t1.setText("Reversed String: " + reversed);
        // JOptionPane.showMessageDialog(this, "Reversed number: " + reversed);
    }

    public static void main(String[] args) {
        new ReverseButton(); // Create an instance of ReverseButton
    }
}
