package demo.sunqi13.myapplication

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val str = stringFromJNI()
        Log.d("sunqi_log", "stringFromJNI : $str")
    }

    // Used to load the 'native-lib' library on application startup.
    external fun stringFromJNI(): String?

    companion object {
        init {
            System.loadLibrary("native-demo")
        }
    }
}