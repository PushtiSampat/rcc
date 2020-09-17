 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      14_17-BitDemo-and-Shift-Operators.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class JavaOperators_Bit{
    public static void main(String[] args){

        // Bitwise Operators

        int a = 65;  // 100 000 1
        int b = 12;  // 000 110 0

        System.out.println(a & b);  //000 000 0
        System.out.println(a | b);  //100 110 1
        System.out.println(a ^ b);  //100 110 1
        System.out.println(~a);     //111 001 0

        System.out.println();

        // Bit Shift
        int c = -10;
        var d = -10L;
        System.out.println(c << 2);
        System.out.println(c >> 2);
        System.out.println(c >>> 2);  // Unsigned

        System.out.println();
        System.out.println(d << 2);
        System.out.println(d >> 2);
        System.out.println(d >>> 2);  // Unsigned Right Shift
        // There is no unsigned Left Shift
    }
}



/* ===========================================================
Output: 

0
77
77
-66

-40
-3
1073741821

-40
-3
4611686018427387901

 =========================================================== */