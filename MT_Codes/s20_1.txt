A) Create an Android Application that will change color of the screen and change the font size of text
view using xml.



Activity_main.xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:orientation="vertical"
tools:context=".MainActivity">
<TextView
android:id="@+id/tv"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="Hello World!"
android:textSize="50dp"/>
<Button
android:id="@+id/b"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="Change Color"/>
</LinearLayout>
MainActivity.java
package com.example.mychange_color;
import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
TextView tv;
Button b1;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
tv=(TextView)findViewById(R.id.tv);
b1=(Button)findViewById(R.id.b);
b1.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View v) {
tv.setTextSize(20);
changecolor(Color.RED);
}
});
}
public void changecolor(int c)
{
View v=this.getWindow().getDecorView();
v.setBackgroundColor(c);
}
}
