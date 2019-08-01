package FirstLab;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class SeventhTask {
    void completeSeventhTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        ArrayList<String> new_buffer = new ArrayList<>();
        int index, length_to_delete;
        Scanner input;
        System.out.print("Write the length of the words to delete: ");
        while (true) {
            input = new Scanner(System.in);
            try {
                length_to_delete = input.nextInt();
                break;
            }
            catch (InputMismatchException fg) {
                System.out.print("Write the correct number: ");
            }
        }
        for (index = 0; index < buffer.size(); index++) {
            String temp = "";
            for (String word : buffer.get(index).split(" ")) {
                if (word.length() != length_to_delete || word.charAt(0) == 'a' || word.charAt(0) == 'u' || word.charAt(0) == 'i' ||
                        word.charAt(0) == 'o' || word.charAt(0) == 'e' || word.charAt(0) == 'A' || word.charAt(0) == 'U' || word.charAt(0) == 'I' ||
                        word.charAt(0) == 'O' || word.charAt(0) == 'E' || word.charAt(0) == 'а' || word.charAt(0) == 'е' || word.charAt(0) == 'ё' ||
                        word.charAt(0) == 'и' || word.charAt(0) == 'о' || word.charAt(0) == 'у' || word.charAt(0) == 'ы' || word.charAt(0) == 'э' ||
                        word.charAt(0) == 'ю' || word.charAt(0) == 'я' || word.charAt(0) == 'А' || word.charAt(0) == 'Е' || word.charAt(0) == 'Ё' ||
                        word.charAt(0) == 'И' || word.charAt(0) == 'О' || word.charAt(0) == 'У' || word.charAt(0) == 'Э' ||
                        word.charAt(0) == 'Ю' || word.charAt(0) == 'Я') {
                    temp += word + " ";
                }
            }
            new_buffer.add(temp);
        }
        for (index = 0; index < new_buffer.size(); index++) {
            System.out.println(new_buffer.get(index));
        }
    }
}
