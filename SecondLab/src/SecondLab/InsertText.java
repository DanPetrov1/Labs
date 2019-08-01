package SecondLab;

import java.util.ArrayList;
import java.util.Scanner;

public class InsertText {
    ArrayList<String> insertText() {
        ArrayList<String> buffer = new ArrayList<>();
        for (String temp = new Scanner(System.in).nextLine(); temp.length() > 0; temp = new Scanner(System.in).nextLine()) {
            buffer.add(temp);
        }
        return buffer;
    }
}
