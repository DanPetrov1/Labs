package FirstLab;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ChooseTask {
    void chooseTask() {
        while (true) {
            Scanner input;
            int chooseVariant;
            System.out.println("Choose the task:\n1. Write N strings, find the smallest string. " +
                    "Output this string and its length.\n2. Write N strings and sort them ascending.\n" +
                    "3. Write N strings. Output the strings with length, which is smaller than average. \n" +
                    "4. Write text. Change the letter in every k position in all words.\n5. Write the text (Russian)" +
                    "write to spaces between every letter and write the number of the alphabet for all letters.\n" +
                    "6. Delete all symbols which aren't alpha.\n7. Delete all words from text with length k.\n8. " +
                    "Find the number of the same words.\n9. Exit");
            while (true) {
                input = new Scanner(System.in);
                try {
                    chooseVariant = input.nextInt();
                    break;
                }
                catch (InputMismatchException fg) {
                    System.out.print("Write the correct number: ");
                }
            }
            switch (chooseVariant) {
                case 1:
                    FirstTask firstTask = new FirstTask();
                    firstTask.completeFirstTask();
                    break;
                case 2:
                    SecondTask secondTask = new SecondTask();
                    secondTask.completeSecondTask();
                    break;
                case 3:
                    ThirdTask thirdTask = new ThirdTask();
                    thirdTask.completeThirdTask();
                    break;
                case 4:
                    ForthTask forthTask = new ForthTask();
                    forthTask.completeForthTask();
                    break;
                case 5:
                    FifthTask fifthTask = new FifthTask();
                    fifthTask.completeFifthTask();
                    break;
                case 6:
                    SixthTask sixthTask = new SixthTask();
                    sixthTask.completeSixthTask();
                    break;
                case 7:
                    SeventhTask seventhTask = new SeventhTask();
                    seventhTask.completeSeventhTask();
                    break;
                case 8:
                    EighthTask eighthTask = new EighthTask();
                    eighthTask.completeEighthTask();
                    break;
                case 9:
                    return;
                default:
                    System.out.println("Choose the correct variant!");
                    break;
            }
        }
    }
}
