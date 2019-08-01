package FirstLab;

import java.util.ArrayList;

public class SixthTask {
    void completeSixthTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        ArrayList<String> new_buffer = new ArrayList<>();
        int index, char_index;
        for (index = 0; index < buffer.size(); index++) {
            String temp = "";
            for (char_index = 0; char_index < buffer.get(index).length(); char_index++) {
                if(Character.isLetter(buffer.get(index).charAt(char_index))) {
                    if (temp.length() != 0 && temp.charAt(temp.length() - 1) != ' ') {
                        temp += " ";
                    }
                    temp += buffer.get(index).charAt(char_index);
                }
                if (buffer.get(index).charAt(char_index) == ' ') {
                    temp += ' ';
                }
            }
            new_buffer.add(temp);
        }
        for (index = 0; index < new_buffer.size(); index++) {
            System.out.println(new_buffer.get(index));
        }
    }
}
