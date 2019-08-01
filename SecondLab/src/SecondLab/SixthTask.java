package SecondLab;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SixthTask {
    void completeSixthTask() {
        System.out.print("Write the text: ");
        InsertText insertText = new InsertText();
        ArrayList<String> text = insertText.insertText();
        Pattern pattern = Pattern.compile("(\\d{2}/){2}\\d{4}");
        check : for(int index = 0; index < text.size(); index++) {
            Matcher matcher = pattern.matcher(text.get(index));
            if (matcher.matches()) {
                int year, month, day;
                day = (text.get(index).charAt(0) - '0') * 10 + text.get(index).charAt(1) - '0';
                month = (text.get(index).charAt(3) - '0') * 10 + text.get(index).charAt(4) - '0';
                year = (text.get(index).charAt(6) - '0') * 1000 + (text.get(index).charAt(7) - '0') * 100 +
                        (text.get(index).charAt(8) - '0') * 10 + text.get(index).charAt(9) - '0';
                if (month == 0 || month > 12 || day == 0 || day > 31) {
                    continue check;
                }
                if (day > 30) {
                    if (month == 4 || month == 6 || month == 9 || month == 11) {
                        continue check;
                    }
                }
                if (day > 28 && month == 2) {
                    if (day > 29 || year % 4 != 0) {
                        continue check;
                    }
                }
                System.out.println("Correct date - " + (index+1) + ": " + text.get(index));
            }
        }
    }
}
