package demo.sunqi13.myapplication

/**
 * Created by sunqi13 on 2021/2/25.
 */
object MediaUtils {
    init {
        System.loadLibrary("native-demo")
    }

    external fun play() :String?
    external fun pause() :String?
    external fun stop() :String?
}