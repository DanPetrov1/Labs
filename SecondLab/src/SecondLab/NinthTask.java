package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class NinthTask {
    void completeNinthTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("\\d{6}");
        for (int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches() && text.get(index).charAt(0) != '0') {
                System.out.println("The correct number - " + (index + 1) + " : " + text.get(index));
            }
        }
    }
}
