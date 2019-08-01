package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FifthTask {
    void completeFifthTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("#((\\p{XDigit}){6})");
        for(int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                System.out.println("Correct color - " + (index+1) + ": " + text.get(index));
            }
        }
    }
}
