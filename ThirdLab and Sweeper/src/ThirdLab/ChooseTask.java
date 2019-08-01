package ThirdLab;

import java.util.*;

public class ChooseTask {
    void chooseTask() throws Exception {
        while (true) {
            Scanner input;
            int chooseVariant;
            System.out.println("Choose the variant of the task:\n1. Read text fom a file, add it to a stack. Write in the file.\n2. " +
                    "Write the numbers into the stack, make from them new number.\n3. Sum two polynomials.\n4. \n5.\n6.\n7.\n8.\n" +
                    "9.\n10. Exit.");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            chooseVariant = input.nextInt();
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
                    ninthTask.setVisible(true);
                    break;
                case 10:
                    new stringMoving();
                    break;
                case 11:
                    TenthTask tenthTask = new TenthTask();
                    break;
                case 12:
                    return;
            }
        }
    }
}
