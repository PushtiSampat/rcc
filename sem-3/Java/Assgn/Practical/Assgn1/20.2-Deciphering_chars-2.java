 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      20.2-Deciphering_chars-2.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class LetterCheck2 {
    public static void main(String[] args) {
        char symbol = 'A';
        symbol = (char)(128.0*Math.random());
        System.out.println(symbol);

        if(symbol >= 'A' && symbol <= 'Z')
            System.out.println("You have the capital letter " + symbol);

        else {
            if(symbol >= 'a' && symbol <= 'z')
                System.out.println("You have the small letter " + symbol);
            else
                System.out.println("The code is not a letter");
        }
    }
}


/* ===========================================================
Output: 

R
You have the capital letter R

 =========================================================== */

/* ===========================================================
Output: 


The code is not a letter

 =========================================================== */
