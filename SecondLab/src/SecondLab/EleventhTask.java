package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EleventhTask {
    void completeEleventhTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        for (int index = 0; index < text.size(); index++) {
            Pattern pattern = Pattern.compile("[\\d\\*\\-\\+\\/\\(\\)\\ ]+");
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                pattern = Pattern.compile("(\\()");
                int number_open = 0;
                for (String word : pattern.split(text.get(index))) {
                    number_open++;
                }
                pattern = Pattern.compile("(\\))");
                int number_close = 0;
                for (String word : pattern.split(text.get(index))) {
                    number_close++;
                }
                if (text.get(index).charAt(text.get(index).length() - 1) == ')') {
                    number_close++;
                }
                if (text.get(index).charAt(text.get(index).length() - 1) == '(') {
                    number_open++;
                }
                if (number_open == number_close) {
                    System.out.println("The correct expression - " + (index + 1) + " : " + text.get(index));
                }
            }
        }
    }
}
