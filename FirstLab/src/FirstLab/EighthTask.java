package FirstLab;

import java.util.ArrayList;
import java.util.Scanner;

public class EighthTask {
    void completeEighthTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        System.out.print("Write the word: ");
        int number = 0;
        String word = new Scanner(System.in).nextLine();
        for (int index = 0; index < buffer.size(); index++) {
            for (String Word : buffer.get(index).split(" ")) {
                if (Word.equals(word)) {
                    number++;
                }
            }
        }
        System.out.println("The number of the same words is " + number);
    }
}
