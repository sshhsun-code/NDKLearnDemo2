package demo.sunqi13.myapplication

/**
 * Created by sunqi13 on 2021/2/25.
 */
class Test {
    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }
}