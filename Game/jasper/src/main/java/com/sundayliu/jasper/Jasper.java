package com.sundayliu.jasper;

/**
 * Created by gavingu on 16/7/1.
 */
public class Jasper {
    public static int sub(int a, int b)
    {
        return a - b;
    }


    public static native String getString();

    static{
        System.loadLibrary("jasper");
    }
}
