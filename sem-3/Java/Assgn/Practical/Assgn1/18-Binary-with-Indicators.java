 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      18-Binary-with-Indicators.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 import static java.lang.Integer.toBinaryString;


class BinaryWithIndicators{
    public static void main(String[] args){
        int indicators = 0xFF07;
        int selectBit3 = 0x4;

        System.out.println("Indicators: "  + toBinaryString(indicators));
        System.out.println("Indicators: "  + toBinaryString(selectBit3));

        indicators &= selectBit3;
        System.out.println("indicators: " +  toBinaryString(indicators));
        System.out.println("selectBit3: " +  toBinaryString(selectBit3));

        indicators &= selectBit3;
        System.out.println("indicators: " +  toBinaryString(indicators));
        System.out.println("selectBit3: " +  toBinaryString(selectBit3));

        indicators = 0xFF09;
        System.out.println("indicators: " +  toBinaryString(indicators));
        System.out.println("selectBit3: " +  toBinaryString(selectBit3));
 
        indicators |= selectBit3;
        System.out.println("indicators | selectBit3: " + toBinaryString(indicators));

        indicators &=  ~selectBit3;
        System.out.println("Switched Off");
        System.out.println(toBinaryString(indicators));
    }
}



/* ===========================================================
Output: 

Indicators: 1111111100000111
Indicators: 100
indicators: 100
selectBit3: 100
indicators: 100
selectBit3: 100
indicators: 1111111100001001
selectBit3: 100
indicators | selectBit3: 1111111100001101
Switched Off
1111111100001001

 =========================================================== */