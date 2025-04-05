package com.jeanboy.demo.jnitest;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void jniTest(View v) {
        // 创建 SimpleDateFormat 对象并指定格式
        //SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        SimpleDateFormat sdf = new SimpleDateFormat("mm:ss.SSS");
        // 获取当前时间
        Date now = new Date(NdkTest.getTimestampMillis());
        // 格式化为字符串
        String currentTime = sdf.format(now);
        Toast.makeText(this, currentTime + "  " + NdkTest.getString(), Toast.LENGTH_SHORT).show();
    }

    public void jniTest2(View v) {
        long tsMs = NdkTest.getTimestampMillis();
        int ia = (int) (tsMs / 3 % 100);
        int ib = (int) (-tsMs * 2 / 3 % 10);
        int ir = NdkTest.doAdd(ia, ib);
        String str = ia + (ib >= 0 ? "+" : "") + ib + "=" + ir;
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }
}
