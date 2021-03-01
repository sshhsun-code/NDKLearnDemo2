package demo.sunqi13.myapplication;

/**
 * Created by sunqi13 on 2021/2/25.
 */
class TimeUtils {
    public native int getNum(int input);

    public native void getNum2(int input);

    public native int getNum3(int[] input);

    public native void printEachChar(String input);

    String testFiled = "this is a testFiled";
    static int  staticTestFiled = 15;
    static long  staticTestLongFiled = 16666;
    public native void testFiled();

}
