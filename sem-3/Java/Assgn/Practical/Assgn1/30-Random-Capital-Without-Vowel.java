 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      30-Random-Capital-Without-Vowel.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class RandomCapital{
    public static void main(String[] args){
        System.out.println("This code will generate 5 Random" + 
                "Capital Letters without any Vowels in it");
        int count = 5;

        for(int i = 0; i < 5;){
            char c = (char)(128.0 * Math.random());
            if(c > 65 && c <=90){
                i++;
                if (c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    i--;
                else
                    System.out.print(c);
            }
        }
    }
}



/* ===========================================================
Output: 

This code will generate 5 RandomCapital Letters without any Vowels in it
SGJCR

 =========================================================== */

/* ===========================================================
Output: 

This code will generate 5 RandomCapital Letters without any Vowels in it
VZBCG

 =========================================================== */

/* ===========================================================
Output: 

This code will generate 5 RandomCapital Letters without any Vowels in it
GJPRW

 =========================================================== */

/* ===========================================================
Output: 

This code will generate 5 RandomCapital Letters without any Vowels in it
HXCSR

 =========================================================== */

/* ===========================================================
Output: 

This code will generate 5 RandomCapital Letters without any Vowels in it
YXFDH

 =========================================================== */