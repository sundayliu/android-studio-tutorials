package com.sundayliu.libhello;

/**
 * Created by gavingu on 16/7/1.
 */
public class Native {
    public static native String getStringFromJNI();

    static{
        //System.loadLibrary("hello");
    }
}
