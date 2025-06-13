package com.test.util;

import java.util.Scanner;



//输入工具类
public class InputUtil {

    private static final Scanner scanner = new Scanner(System.in);
    //用以输入字符串
    public static String nextLine(String s){
        System.out.println(s);
        return scanner.nextLine();
    }


    //用以输入整型
    public static int nextInt(String s){
        System.out.println(s);
        while (true){
            try {
                return scanner.nextInt();
            } catch (Exception e) {
                System.out.println("您输入的值不合法");
                scanner.nextLine();//跳过换行符，否则会继续读原来的值造成死循环
            }
        }
    }

}
