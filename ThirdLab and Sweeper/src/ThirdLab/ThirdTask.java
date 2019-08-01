package ThirdLab;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ThirdTask {
    void completeThirdTask() {
        System.out.println("Write the degree and coefficient of two polynomials.");
        HashMap<Integer, Integer> integerHashMap = new HashMap<>();
        HashMap<Integer, Integer> integerHashMap1 = new HashMap<>();
        int degree = 1, coefficient, index;
        Scanner input;
        System.out.println("First polynomial:");
        while (degree != 0) {
            System.out.print("Write the degree: ");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            degree = input.nextInt();
            System.out.print("Write the coefficient: ");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            coefficient = input.nextInt();
            integerHashMap.put(degree, coefficient);
        }
        degree = 1;
        System.out.println("Second polynomial:");
        while (degree != 0) {
            System.out.print("Write the degree: ");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            degree = input.nextInt();
            if (!integerHashMap.containsKey(degree)) {
                integerHashMap.put(degree, 0);
            }
            System.out.print("Write the coefficient: ");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                System.out.println("Write the correct number!");
                input.next();
            }
            coefficient = input.nextInt();
            integerHashMap1.put(degree, coefficient);
        }
        for (Map.Entry<Integer, Integer> item : integerHashMap1.entrySet()) {
            integerHashMap.put(item.getKey(), (integerHashMap1.get(item.getKey()) + integerHashMap.get(item.getKey())));
        }
        System.out.println("The polynomial is:");
        boolean flag = false;
        for (Map.Entry<Integer, Integer> item : integerHashMap.entrySet()) {
            if (!flag) {
                flag = true;
            } else {
                System.out.print('+');
            }
            System.out.print(item.getValue() + "*X^" + item.getKey());
        }
        System.out.println(" ");
    }
}
