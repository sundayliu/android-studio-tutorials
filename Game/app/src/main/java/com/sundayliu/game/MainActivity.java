package com.sundayliu.game;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.sundayliu.libhello.*;
import com.sundayliu.jasper.*;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView)findViewById(R.id.tv_hello);
        String text = "[jasper]1 - 2 = " + Jasper.sub(1,2);
        tv.setText(text);

        tv = (TextView)findViewById(R.id.tv_add);
        text = "[hello]1 + 2 = " + Hello.add(1,2);
        tv.setText(text);
    }
}
