package demo.sunqi13.myapplication

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    companion object {
        init {
            System.loadLibrary("native-demo")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val str = stringFromJNI()
        Log.d("sunqi_log", "stringFromJNI : $str")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.play()}")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.pause()}")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.stop()}")
    }

    // Used to load the 'native-lib' library on application startup.
    external fun stringFromJNI(): String?
}