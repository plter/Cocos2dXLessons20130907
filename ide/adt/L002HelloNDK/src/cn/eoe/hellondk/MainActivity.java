package cn.eoe.hellondk;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        System.loadLibrary("ndk");
        
        System.out.println(">>>>>>>>>>>>>>"+new Bridge().getNum());
        System.out.println(">>>>>>>>>>>>>>"+NativeMath.max(2, 3));
    }
    

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
