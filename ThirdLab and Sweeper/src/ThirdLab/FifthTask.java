package ThirdLab;

import java.util.Scanner;
import java.util.Stack;

public class FifthTask {
    void completeFifthTask() {
        System.out.println("Write the numbers in the first stack:");
        Scanner input;
        Stack<Integer> integerStack = new Stack<>();
        input : while (true) {
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                break input;
            }
            integerStack.push(input.nextInt());
        }
        System.out.println("Write the numbers in the second stack:");
        Stack<Integer> integerStack1 = new Stack<>();
        input : while (true) {
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                break input;
            }
            integerStack1.push(input.nextInt());
        }
        Stack<Integer> buffer = new Stack<>();
        int index = integerStack.size();
        while (!integerStack1.empty()) {
            buffer.push(integerStack1.pop());
        }
        while (!integerStack.empty()) {
            buffer.push(integerStack.pop());
        }
        for (int number = 0; number < index; number++) {
            integerStack1.push(buffer.pop());
        }
        while(!buffer.empty()) {
            integerStack.push(buffer.pop());
        }
        System.out.println("The task completed successfully!");
    }
}
