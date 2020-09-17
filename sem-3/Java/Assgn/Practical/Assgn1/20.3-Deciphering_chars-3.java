 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      20.3-Deciphering_chars-3.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 import static java.lang.Character.isLowerCase;
import static java.lang.Character.isUpperCase;

class LetterCheck3 {
    public static void main(String[] args) {
        char symbol;
        symbol = (char)(128.0*Math.random());
        System.out.println(symbol);

        if(isUpperCase(symbol))
            System.out.println("You have the capital letter: " + symbol);
        else {
            if(isLowerCase(symbol))
                System.out.println("You have the small letter: " + symbol);
            else
                System.out.println("The code is not a letter");
        }
    }
}


/* ===========================================================
Output: 

|
The code is not a letter

 =========================================================== */