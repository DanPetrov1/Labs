package FirstLab;

import java.util.*;

public class FirstTask {
    void completeFirstTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        int min_length = 0, index = 0, min_index = 0;
        while(buffer.size() > index) {
            if (index == 0 || min_length > buffer.get(index).length()) {
                min_length = buffer.get(index).length();
                min_index = index;
            }
            index++;
        }
        System.out.println("The size of the smallest string is " + min_length);
        System.out.println("The smallest string: " + buffer.get(min_index));
    }
}
