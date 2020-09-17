 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      03_04-Arithmetic.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class Arithmetic{
    public static void main(String[] args){

        System.out.println("N1: 25, N2: 10\n");
        int a = 25;
        int b = 10;

        /* Arithmetic Operations on Integer */
        System.out.println("Arithmetic Operations on Int");

        // Addition
        int add = a + b;
        System.out.println("-Addition: " + add);
        
        // Subtarction
        int sub = a - b;
        System.out.println("-Subtraction: " + sub);

        // Multiplication
        int mul = a * b;
        System.out.println("-Multiplication: " + mul);

        // Division
        int div = a / b;
        System.out.println("-Division: " + div);

        // Modulo Division
        int mod = a % b;
        System.out.println("-Modulo: " + mod);

        // Unary Minus
        int minus = -a;
        System.out.println("-Unary Minus of N1: " + minus);


        /* Arithmetic Operations on Float */
        System.out.println("\nArithmetic Operations on Float");

        float x = 25f;
        float y = 10f;

        // Addition
        float addF = x + y;
        System.out.println("-Addition: " + addF);
        
        // Subtarction
        float subF = x - y;
        System.out.println("-Subtraction: " + subF);

        // Multiplication
        float mulF = x * y;
        System.out.println("-Multiplication: " + mulF);

        // Division
        float divF = x / y;
        System.out.println("-Division: " + divF);

        // Modulo Division
        float modF = x % y;
        System.out.println("-Modulo: " + modF);

        // Unary Minus
        float minusF = -a;
        System.out.println("-Unary Minus of N1: " + minusF);
    }
}


/* ===========================================================
Output: 

N1: 25, N2: 10

Arithmetic Operations on Int
-Addition: 35
-Subtraction: 15
-Multiplication: 250
-Division: 2
-Modulo: 5
-Unary Minus of N1: -25

Arithmetic Operations on Float
-Addition: 35.0
-Subtraction: 15.0
-Multiplication: 250.0
-Division: 2.5
-Modulo: 5.0
-Unary Minus of N1: -25.0

 =========================================================== */