package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EighthTask {
    void completeEighthTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("([_\\w]{8,})");
        Pattern pattern1 = Pattern.compile("_");
        Pattern pattern2 = Pattern.compile("\\p{javaUpperCase}");
        Pattern pattern3 = Pattern.compile("\\p{javaLowerCase}");
        Pattern pattern4 = Pattern.compile("\\d");
        for (int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                matcher = pattern1.matcher(text.get(index));
                if (matcher.find()) {
                    matcher = pattern2.matcher(text.get(index));
                    if (matcher.find()) {
                        matcher = pattern3.matcher(text.get(index));
                        if (matcher.find()) {
                            matcher = pattern4.matcher(text.get(index));
                            if (matcher.find()) {
                                System.out.println("The correct password is - " + (index + 1) + " : " + text.get(index));
                            }
                        }
                    }
                }
            }
        }
    }
}
