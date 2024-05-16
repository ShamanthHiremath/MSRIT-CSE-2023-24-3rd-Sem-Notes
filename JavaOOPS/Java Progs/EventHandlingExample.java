import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EventHandlingExample extends JFrame {
    private JButton msritButton, rvButton, pesuButton;
    private JLabel label;

    public EventHandlingExample() {
        // Set window title
        super("Event Handling Example");

        // Create buttons
        msritButton = new JButton("MSRIT");
        rvButton = new JButton("RV");
        pesuButton = new JButton("PESU");

        // Create label to display message
        label = new JLabel("Welcome");

        // Add action listeners to buttons
        msritButton.addActionListener(e-> {label.setText("hello swing");});
        rvButton.addActionListener(new ButtonListener("Welcome RV"));
        pesuButton.addActionListener(new ButtonListener("Welcome PESU"));

        // Add components to the content pane
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.add(msritButton);
        c.add(rvButton);
        c.add(pesuButton);
        c.add(label);
    }

    private class ButtonListener implements ActionListener {
        private String message;

        public ButtonListener(String message) {
            this.message = message;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            // Update label with the appropriate message when a button is clicked
            label.setText(message);
        }
        // public void actionPerformed(ActionEvent e) {
        //     // Display popup message with the appropriate welcome message when a button is clicked
        //     JOptionPane.showMessageDialog(EventHandlingExample.this, message, "Welcome Message", JOptionPane.INFORMATION_MESSAGE);
        // }
    }

    public static void main(String[] args) {
        // Create and configure the JFrame
        EventHandlingExample frame = new EventHandlingExample();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 150);
        frame.setVisible(true);
    }
}
