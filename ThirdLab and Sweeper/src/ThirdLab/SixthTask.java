package ThirdLab;

import java.util.Scanner;
import java.util.Stack;

public class SixthTask {
    void completeSixthTask() {
        System.out.println("Write the numbers in the stack:");
        Scanner input;
        Stack<Integer> integerStack = new Stack<>();
        int number;
        input : while (true) {
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                break input;
            }
            integerStack.push(input.nextInt());
        }
        Stack<Integer> buffer = new Stack<>();
        while(integerStack.size() != 1) {
            while (!integerStack.empty()) {
                number = integerStack.pop();
                System.out.print(number + " ");
                if (!integerStack.empty()) {
                    number += integerStack.peek();
                    System.out.print(integerStack.pop() + " ");
                }
                buffer.push(number);
            }
            System.out.println(" ");
            while (!buffer.empty()) {
                number = buffer.pop();
                System.out.print(number + " ");
                if (!buffer.empty()) {
                    number += buffer.peek();
                    System.out.print(buffer.pop() + " ");
                }
                integerStack.push(number);
            }
            System.out.println(" ");
        }
        System.out.println(integerStack.pop());
    }
}
