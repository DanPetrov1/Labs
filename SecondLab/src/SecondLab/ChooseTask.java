package SecondLab;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ChooseTask {
    void chooseTask() {
        while (true) {
            Scanner input;
            int chooseVariant;
            System.out.println("Choose the variant of the task:\n1. Correct \"abcdefghijklmnopqrstuv18340\".\n2. Correct GUID.\n" +
                    "3. Correct MAC-address\n4. Correct URL.\n5. Correct color (hexadecimal code).\n6. Correct date.\n7. Correct IP address.\n8. " +
                    "Correct password.\n9. Six-digit number.\n10. Digits after \"+\"\n11. Correct expression.\n12. Exit.");
            //while (!(input != new Scanner(System.in).hasNextInt()))
            while (true) {
                input = new Scanner(System.in);
                try {
                    chooseVariant = input.nextInt();
                    break;
                } catch (InputMismatchException fg) {
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
                    NinthTask ninthTask = new NinthTask();
                    ninthTask.completeNinthTask();
                    break;
                case 10:
                    TenthTask tenthTask = new TenthTask();
                    tenthTask.completeTenthTask();
                    break;
                case 11:
                    EleventhTask eleventhTask = new EleventhTask();
                    eleventhTask.completeEleventhTask();
                    break;
                case 12:
                    return;
                default:
                    System.out.println("Write the correct number!");
                    break;
            }
        }
    }
}
