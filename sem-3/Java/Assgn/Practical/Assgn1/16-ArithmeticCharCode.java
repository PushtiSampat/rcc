 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      16-ArithmeticCharCode.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class CharCodeCalcs {
    public static void main(String[] args){
        char letter1 = 'A';
        char letter2 = (char)(letter1+1);
        char letter3 = letter2;

        System.out.println("Here\'s a sequence of letters: "+ letter1 + letter2 +
                (++letter3));

        System.out.println("Here are the decimal codes for the letters:\n"+
                letter1 + ": " + (int)letter1 +
                " " + letter2 + ": " + (int)letter2 +
                " " + letter3 + ": " + (int)letter3);
    }
}


/* ===========================================================
Output: 

Here's a sequence of letters: ABC
Here are the decimal codes for the letters:
A: 65 B: 66 C: 67

 =========================================================== */