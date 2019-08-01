package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TenthTask {
    void completeTenthTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("[\\d\\*\\-\\+\\/\\(\\)\\ ]+");
        for (int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                pattern = Pattern.compile("\\+");
                matcher = pattern.matcher(text.get(index));
                if (matcher.find()) {
                    int plus_index = matcher.end();
                    pattern = Pattern.compile("\\d");
                    matcher = pattern.matcher(text.get(index));
                    if (matcher.find(plus_index)) {
                        System.out.println("The correct expression - " + (index + 1) + " : " + text.get(index));
                    }
                }
            }
        }
    }
}
