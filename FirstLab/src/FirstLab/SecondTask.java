package FirstLab;

import java.util.ArrayList;

public class SecondTask {
    void completeSecondTask() {
        InsertText insert = new InsertText();
        ArrayList<String> buffer = insert.insertText();
        for (int i = 0; i < buffer.size() - 1; i++) {
            for (int j = buffer.size() - 1; j > i; j--) {
                if (buffer.get(i).compareTo(buffer.get(j)) > 0) {
                    String Buffer = buffer.get(i);
                    buffer.set(i, buffer.get(j));
                    buffer.set(j, Buffer);
                }
            }
        }
        for (int i = 0; i < buffer.size(); i++) {
            System.out.println(buffer.get(i));
        }
    }
}
