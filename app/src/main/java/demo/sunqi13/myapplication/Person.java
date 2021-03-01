package demo.sunqi13.myapplication;

import android.util.Log;

/**
 * Created by sunqi13 on 2021/3/1.
 */
public class Person {
    private int age;
    private String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public void print() {
        Log.e("sunqi_log Person", name + age + "岁了");
    }
}

