package com.itransition.hashing;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class Hashing {
    public static StringBuilder getHashCode(String string) throws NoSuchAlgorithmException {
        MessageDigest sha3 = MessageDigest.getInstance("SHA-256");
        byte[] bytes = sha3.digest(string.getBytes());
        StringBuilder builder = new StringBuilder();
        for (byte b : bytes) {
            builder.append(String.format("%x", b));
        }
        return builder;
    }

    public static void main(String args[]) throws NoSuchAlgorithmException, ArrayIndexOutOfBoundsException {
        for (String string : args) {
            if (string.charAt(0) == '0') {
                System.out.println("Out");
                return;
            }
            Random random = new Random(System.currentTimeMillis());
            int opponents_number = 1 + random.nextInt(3);
            StringBuilder my_move = getHashCode(string);
            if (getHashCode(String.valueOf((opponents_number + 1) % 3)).toString().equals(my_move.toString())) {
                System.out.println("You win!");
                return;
            } else if (getHashCode(String.valueOf((opponents_number - 1) % 3)).toString().equals(my_move.toString())) {
                System.out.println("You lose!");
                return;
            }
        }
    }
}
