package ThirdLab;

import java.io.*;
import java.util.Stack;

public class FirstTask {
    void completeFirstTask() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        File file = new File("D:/img/File.txt");
        if (!file.isFile()) {
            System.out.println("There's no file on that directory!");
            return;
        }
        BufferedReader bufferedReader = new BufferedReader(new FileReader(file));
        String line, name;
        System.out.println("Print File \""+file.getName()+"\"? Y/N");
        name = br.readLine();
        Stack<String> stringStack = new Stack<>();
        if(name.equals("y")) {
            while ((line = bufferedReader.readLine()) != null)  {
                System.out.println(line);
                stringStack.push(line);
            }
        }
        bufferedReader.close();
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
        while (!stringStack.empty()) {
            line = stringStack.pop();
            bufferedWriter.write(line + "\n");
        }
        bufferedWriter.close();
        System.out.println("The task is completed successfully!");
    }
}
