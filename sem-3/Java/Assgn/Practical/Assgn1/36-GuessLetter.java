 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      36-GuessLetter.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class GuessLetter{
    public static void main(String[] args){
        char c = args[0].charAt(0);
        int count = 1;

        for(;;){
            char symbol = (char)(128.0 * Math.random());
            if(symbol == c){
                System.out.print("Correct Guess ");
                System.out.println("at " + count + " time");
                break;
            }
            else{
                System.out.println("Oops! The Letter was: " + symbol);
                count++;
            }
        }
    }
}


/* ===========================================================
Output: 

GuessLetter w

Oops! The Letter was: e
Oops! The Letter was: N
Oops! The Letter was: p
Oops! The Letter was: )
Oops! The Letter was: l
Oops! The Letter was: 
Oops! The Letter was: !
Oops! The Letter was: 	
Oops! The Letter was: 0
Oops! The Letter was: E
Oops! The Letter was: A
Oops! The Letter was: )
Oops! The Letter was: 
Oops! The Letter was: x
Oops! The Letter was: !
Oops! The Letter was: @
Oops! The Letter was: 3
Oops! The Letter was: x
Oops! The Letter was: 
Oops! The Letter was: `
Oops! The Letter was: 
Oops! The Letter was: +
Oops! The Letter was: :
Oops! The Letter was: f
Oops! The Letter was: .
Oops! The Letter was: N
Oops! The Letter was: F
Oops! The Letter was: h
Oops! The Letter was: o
Oops! The Letter was: 
Oops! The Letter was: 
Oops! The Letter was: 
Oops! The Letter was: -
Oops! The Letter was: "
Oops! The Letter was: 6
Oops! The Letter was: =
Oops! The Letter was: 6
Oops! The Letter was: h
Oops! The Letter was: 
Oops! The Letter was: J
Oops! The Letter was: x
Oops! The Letter was: d
Oops! The Letter was: 
Oops! The Letter was: 6
Oops! The Letter was: j
Oops! The Letter was: 
Oops! The Letter was: q
Oops! The Letter was: 
Oops! The Letter was: >
Oops! The Letter was: 6
Oops! The Letter was: Y
Oops! The Letter was: P
Correct Guess at 53 time

 =========================================================== */
