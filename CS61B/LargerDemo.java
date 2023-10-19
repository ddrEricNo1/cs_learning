public class LargerDemo {
    public static int larger(int x, int y) {
        if (x > y) {
            return x;
        }
        return y;
    }
    public static void main(String[] args) {
        System.out.println(larger(-5, 10));
    }
}

/*
1. To define functions in java, functions must be declared as a part of class in java
A function that is part of the class is called a method
2. To define functions in java, we use public static, we will see alternative ways of defining
functions later
3. All parameters and a function must have a declared type, and the returned value of a function must
have one as well. 
 */