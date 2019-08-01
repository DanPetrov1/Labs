package ThirdLab;

import java.util.*;
import java.io.*;

public class ForthTask {
    void completeForthTask() throws Exception {
        String scan = new Scanner(System.in).nextLine();
        Stack<File> fileStack = new Stack<>();
        File dir = new File(String.valueOf(scan));
        getDirectory(fileStack, 0, dir);
        File file = new File("D:/Lab3/Test.txt");
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
        while (!fileStack.empty()) {
            String line = fileStack.pop().toString();
            bufferedWriter.write(line + "\n");
        }
        bufferedWriter.close();
    }
    void getDirectory(Stack<File> fileStack, int index, File file) {
        if (file.isDirectory()) {
            File[] files = file.listFiles();
            /*for (int number = 0; number < index; number++) {
                System.out.print("-");
            }
            System.out.println(file.getName());*/
            for (File tmpFile : files) {
                getDirectory(fileStack, index + 1, tmpFile);
            }
            fileStack.push(file);
        }
    }
}
