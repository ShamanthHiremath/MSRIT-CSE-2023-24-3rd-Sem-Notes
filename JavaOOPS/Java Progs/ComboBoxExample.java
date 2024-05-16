import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ComboBoxExample extends JFrame {
    private JComboBox<String> comboBox;
    private JLabel label;

    public ComboBoxExample() {
        // Set window title
        super("ComboBox Example");

        // Create JComboBox with options
        comboBox = new JComboBox<>(new String[]{"CSE", "ISE", "AIML"});
        comboBox.addActionListener(new ComboBoxListener());

        // Create JLabel to display selected item
        label = new JLabel("Selected option will appear here");

        // Add components to the content pane
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.add(comboBox);
        c.add(label);
    }

    private class ComboBoxListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // Get the selected item from the JComboBox
            String selectedOption = (String) comboBox.getSelectedItem();
            
            // Update the JLabel with the selected item
            label.setText("Selected: " + selectedOption);
        }
    }

    public static void main(String[] args) {
        // Create and configure the JFrame
        ComboBoxExample frame = new ComboBoxExample();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 150);
        frame.setVisible(true);
    }
}
