package com.company;

import javax.swing.*;
import java.awt.event.ActionListener;

public class MainMenuWindow {
    private JFrame frame;
    private JButton start;
    private JButton exit;

    public MainMenuWindow(){
        constructFrame();
        addComponentsToFrame();
        finalSettingOfFrame();
    }

    private void constructFrame(){
        frame = new JFrame("Главное меню");
        start = new JButton("Начало игры");
        exit = new JButton("выход");

        start.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent actionEvent) {
                frame.dispose();
                GameWindow w = new GameWindow();
            }

        });
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent actionEvent) {
                frame.dispose();
            }

        });
        };

    private void addComponentsToFrame() {
        JPanel panel = new JPanel();
        panel.setLayout(null);
        frame.getContentPane().add(panel);
        start.setBounds(190,150,200,50);
        exit.setBounds(190,300,200,50);
        panel.add(start);
        panel.add(exit);
        frame.getContentPane().add(panel);
    };

    private void finalSettingOfFrame() {
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600,600);
        frame.setLocation(600,100);
        frame.setUndecorated(false);
        frame.setVisible(true);
    }

}
