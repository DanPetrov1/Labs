package ThirdLab;

import java.util.ArrayList;
import java.util.Scanner;

public class EighthTask {
    void completeEighthTask() {
        System.out.println("Write the coefficients of the first polynomial:");
        Scanner input;
        ArrayList<Integer> firstList = new ArrayList<>();
        int index = 0;
        System.out.print("\n");
        input : while (true) {
            System.out.print("Write the coefficient of the degree " + index + " : ");
            input = new Scanner(System.in);
            if (!input.hasNextInt()) {
                break input;
            }
            firstList.add(index, input.nextInt());
            index++;
        }
        System.out.println("Write the coefficients of the second polynomial:");
        ArrayList<Integer> secondList = new ArrayList<>();
        index = 0;
        input : while (true) {
            System.out.print("Write the coefficient of the degree " + index + " : ");
            input = new Scanner(System.in);
            while (!input.hasNextInt()) {
                break input;
            }
            secondList.add(index, input.nextInt());
            index++;
        }
        ArrayList<Integer> resultList = new ArrayList<>();
        for (index = 0; index < firstList.size() + secondList.size() - 1; index++) {
            resultList.add(index, 0);
        }
        for (index = 0; index < firstList.size(); index++) {
            for (int secondIndex = 0; secondIndex < secondList.size(); secondIndex++) {
                resultList.set((secondIndex + index), (firstList.get(index) * secondList.get(secondIndex) +
                        resultList.get(secondIndex + index)));
            }
        }
        System.out.print("\n");
        for (index = 0; index < resultList.size(); index++) {
            System.out.print(resultList.get(index) + "*X^" + index);
            if (index < resultList.size() - 1) {
                System.out.print(" + ");
            }
        }
        System.out.print("\n\n");
    }
}
