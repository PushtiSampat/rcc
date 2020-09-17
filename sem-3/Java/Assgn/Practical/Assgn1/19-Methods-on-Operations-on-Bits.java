 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      19-Methods-on-Operations-on-Bits.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 import static java.lang.Long.*;


class TryBitMethods {
    public static void main(String[] args) {
        long number = 0xF00000000000000FL;
        System.out.println("number:\n" + toBinaryString(number));

        long result = rotateLeft(number,2);
        System.out.println("number rotated left 2 bits:\n" + toBinaryString(result));

        result = rotateRight(number, 3);
        System.out.println("number rotated right 3 bits:\n" + toBinaryString(result));

        result = reverse(result);
        System.out.println("Previous result reversed:\n" + toBinaryString(result));
        System.out.println("Bit count in number:\n" + bitCount(number));
    }
}


/* ===========================================================
Output: 

number:
1111000000000000000000000000000000000000000000000000000000001111
number rotated left 2 bits:
1100000000000000000000000000000000000000000000000000000000111111
number rotated right 3 bits:
1111111000000000000000000000000000000000000000000000000000000001
Previous result reversed:
1000000000000000000000000000000000000000000000000000000001111111
Bit count in number:
8

 =========================================================== */