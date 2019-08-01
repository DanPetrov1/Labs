package ThirdLab;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class NinthTask extends JFrame {
    private JButton button = new JButton("Quit");
    private JTextField input = new JTextField("", 5);
    private JLabel label = new JLabel("Input:");
    private JRadioButton radioButton1 = new JRadioButton("Select thi");
    private JRadioButton radioButton2 = new JRadioButton("Select that");
    private JCheckBox check = new JCheckBox("Check");

    public  NinthTask() {
        super("What is it?");
        this.setBounds(100, 100, 250, 250);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

   /* Thread thread=new Thread(new Runnable() {
        @Override
        public void run() {
            Container container = this.getContentPane();
            container.setLayout(new GridLayout(3, 2, 2, 2));
            container.add(label);
            container.add(input);


            ButtonGroup group = new ButtonGroup();
            group.add(radioButton1);
            group.add(radioButton2);
            container.add(radioButton1);
            radioButton1.setSelected(true);
            container.add(radioButton2);
            container.add(check);
            button.addActionListener(new ButtonEventListener());
            container.add(button);
        }
    })
    class ButtonEventListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String message = "";
            message += "Button was pressed\n";
            message += "Text is " + input.getText() + "\n";
            message += ((radioButton1.isSelected() ? "Radio #1" : "Radio #2")) + " is selected.\n";
            message += "Checkbox is " + ((check.isSelected()) ? "checked" : "unchecked") + "\n";
            JOptionPane.showMessageDialog(null, message, "Output", JOptionPane.PLAIN_MESSAGE);
        }
    }*/

}

