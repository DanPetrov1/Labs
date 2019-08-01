package FirstLab;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class ForthTask {
    void completeForthTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        System.out.print("Write the position of letter to change: ");
        int position;
        Scanner input;
        while (true) {
            input = new Scanner(System.in);
            try {
                position = input.nextInt();
                break;
            }
            catch (InputMismatchException fg) {
                System.out.print("Write the correct number: ");
            }
        }
        System.out.print("Write the letter to change: ");
        char letter = new Scanner(System.in).next().charAt(0);
        int index, index_of_strings, check;
        int last_position;
        ArrayList<String> new_buffer = new ArrayList<>();
        for (index_of_strings = 0; index_of_strings < buffer.size(); index_of_strings++) {
            String temp = "";
            for (index = 0, check = 0, last_position = 0; index < buffer.get(index_of_strings).length(); index++) {
                if (buffer.get(index_of_strings).charAt(index) == ' ') {
                    check = 0;
                    continue;
                }
                check++;
                if (check == position) {
                    temp += buffer.get(index_of_strings).substring(last_position, index) + letter;
                    last_position = index + 1;
                }
            }
            temp += buffer.get(index_of_strings).substring(last_position, index - 1);
            new_buffer.add(temp);
        }
        for (index = 0; index < new_buffer.size(); index++) {
            System.out.println(new_buffer.get(index));
        }
    }
}
