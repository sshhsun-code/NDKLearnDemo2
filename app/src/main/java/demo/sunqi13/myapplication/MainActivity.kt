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
        val array : IntArray = intArrayOf(1, 4, 9)
        val array1 = IntArray(5) { it * 1 }
        Log.d("sunqi_log", "stringFromJNI : $str")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.play()}")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.pause()}")
        Log.d("sunqi_log", "MediaUtils : ${MediaUtils.stop()}")
        Log.d("sunqi_log", "TimeUtils getNum : ${TimeUtils().getNum(3)}")
        Log.d("sunqi_log", "TimeUtils getNum2 : ${TimeUtils().getNum2(3)}")
        Log.d("sunqi_log", "TimeUtils getNum3 : ${TimeUtils().getNum3(array)}")
        Log.d("sunqi_log", "TimeUtils getNum3 : ${TimeUtils().getNum3(array1)}")
        TimeUtils().printEachChar("this is a test String")
        TimeUtils().testFiled()
        TimeUtils().testNewObject()

        JniOnLoadTest().dynamicJavaFunc1()
        JniOnLoadTest().dynamicJavaFunc2(18)
    }

    // Used to load the 'native-lib' library on application startup.
    external fun stringFromJNI(): String?
}