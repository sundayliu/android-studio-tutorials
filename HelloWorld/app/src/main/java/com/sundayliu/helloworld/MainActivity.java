package com.sundayliu.helloworld;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String strTest = test();
        TextView v = (TextView)findViewById(R.id.tv_hello);
        v.setText(strTest);

    }

    public static native String test();

    static{
        System.loadLibrary("helloworld");
    }
}
