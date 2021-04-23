package com.ihubin.ndkjni;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    // Java -> Native
    public void java2Native(View view) {
        startActivity(new Intent(this, JavaToNativeActivity.class));
    }

    // Native -> Java
    public void native2Java(View view) {
        startActivity(new Intent(this, JavaFromNativeActivity.class));
    }

    // Java <-> Native
    public void javaNative(View view) {
        startActivity(new Intent(this, JavaNativeActivity.class));
    }

}
