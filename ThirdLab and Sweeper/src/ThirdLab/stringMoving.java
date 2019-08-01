package ThirdLab;

import javax.swing.*;
import java.awt.*;

public class stringMoving extends JFrame {
    private JPanel root;
    stringMoving(){
        setContentPane(root);
        setDefaultCloseOperation(stringMoving.EXIT_ON_CLOSE);
        setSize(600,400);
        setVisible(true);
        Graphics graphics=root.getGraphics();
        while (true) {
            for (int i = -100; i < 700; i++) {
                graphics.drawString("Fuck you, asshole!", i, 200);
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                root.update(graphics);
            }
        }
    }
}
