package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FirstTask {
    void completeFirstTask() {
        System.out.print("Write the text: ");
        Pattern pattern = Pattern.compile("abcdefghijklmnopqrstuv18340");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        for (int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                System.out.println("The string number " + (index + 1) + " is the same.");
            }
        }
    }
}