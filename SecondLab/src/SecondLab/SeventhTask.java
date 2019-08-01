package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SeventhTask {
    void completeSeventhTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("(\\d{1,3}\\.){3}\\d{1,3}");
        check : for(int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                int char_index = 0, number = 0;
                while (char_index < text.get(index).length()) {
                    if (text.get(index).charAt(char_index) == '.') {
                        if (number > 255) {
                            continue check;
                        }
                        number = 0;
                    } else {
                        number = number * 10 + text.get(index).charAt(char_index) - '0';
                    }
                    char_index++;
                }
                if (number > 255) {
                    continue check;
                }
                System.out.println("The correct IP - " + text.get(index));
            }
        }
    }
}
