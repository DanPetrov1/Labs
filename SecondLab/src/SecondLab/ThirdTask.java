package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ThirdTask {
    void completeThirdTask() {
        System.out.print("Write the text: ");
        Pattern pattern = Pattern.compile("(\\p{XDigit}{2})(((-|:)(\\p{XDigit}){2}){5})");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        for(int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                System.out.println("Correct MAC-address - " + (index+1) + ": " + text.get(index));
            }
        }
    }
}
