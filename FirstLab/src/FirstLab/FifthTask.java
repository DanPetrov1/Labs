package FirstLab;

import java.util.ArrayList;

public class FifthTask {
    void completeFifthTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        int index, char_index;
        for (index = 0; index < buffer.size(); index++) {
            String temp = "";
            for (char_index = 0; char_index < buffer.get(index).length(); char_index++) {
                if (buffer.get(index).charAt(char_index) <= 'Я' && buffer.get(index).charAt(char_index) >= 'А') {
                    int letter = buffer.get(index).charAt(char_index) - 'А' + 1;
                    temp += Integer.toString(letter) + " ";
                }
                if (buffer.get(index).charAt(char_index) <= 'я' && buffer.get(index).charAt(char_index) >= 'а') {
                    int letter = buffer.get(index).charAt(char_index) - 'а' + 1;
                    temp += Integer.toString(letter) + " ";
                }
                System.out.print(buffer.get(index).charAt(char_index) + "  ");
            }
            System.out.println("\n" + temp);
        }
    }
}
