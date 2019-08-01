package ThirdLab;

import java.lang.*;

public class TenthTask implements Runnable {
    Thread t;
    TenthTask() {
        t = new Thread(this, "Main");
        t.start();
    }

    @Override
    public void run() {
        System.out.println("Hello world!");
    }
}
