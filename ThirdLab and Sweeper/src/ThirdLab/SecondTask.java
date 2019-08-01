package ThirdLab;

import java.util.Scanner;
import java.util.Stack;

public class SecondTask {
    void completeSecondTask() {
        System.out.println("Write the numbers. The'll be added into the stack. If you want to stop, write 0.");
        Scanner input;
        int number[] = new int[10];
        boolean flag = true;
        int inputNumber, index;
        String outputNumber = "";
        for (index = 0; index < 10;index++) {
            number[index] = 0;
        }
        Stack<Integer> stack = new Stack<>();
        while (flag) {
            flag = false;
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            if ((inputNumber = input.nextInt()) != 0) {
                flag = true;
            }
            while (inputNumber > 0) {
                stack.push(inputNumber % 10);
                inputNumber /= 10;
                number[stack.pop()]++;
            }
        }
        while (!stack.empty()) {
            number[stack.pop()]++;
        }
        for (index = 9; index >= 0; index--) {
            while (number[index] > 0) {
                outputNumber += (index);
                number[index]--;
            }
        }
        System.out.println(outputNumber);
    }
}
