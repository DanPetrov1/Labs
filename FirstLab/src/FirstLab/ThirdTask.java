package FirstLab;

import java.util.ArrayList;
import java.util.Scanner;

public class ThirdTask {
    void completeThirdTask() {
        double average_length = 0;
        System.out.println("Write the text.");
        ArrayList<String> buffer = new ArrayList<>();
        for (String temp = new Scanner(System.in).nextLine(); temp.length() > 0; temp = new Scanner(System.in).nextLine()) {
            buffer.add(temp);
            average_length += temp.length();
        }
        average_length /= buffer.size();
        for (int i = 0; i < buffer.size(); i++) {
            if (average_length > buffer.get(i).length()) {
                System.out.println(buffer.get(i) + " - length: " + buffer.get(i).length());
            }
        }
    }
}