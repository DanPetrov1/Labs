package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SecondTask {
    void completeSecondTask() {
        System.out.print("Write the text: ");
        Pattern pattern = Pattern.compile("(\\p{XDigit}{8})((-(\\p{XDigit}){4}){4})((\\p{XDigit}){8})");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        for(int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                System.out.println("Correct string - " + (index+1) + ": " + text.get(index));
            }
        }
    }
}
