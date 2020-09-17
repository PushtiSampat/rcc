 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      06-if-else.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class IfElse{
    public static void main(String[] args){

        int number = 0;

        // If number is "0"
        if(number == 0){
            System.out.println(number + " is neither even nor odd");
        }

        // If number is Even
        else if (number % 2 == 0){
            System.out.println(number + " is Even");
        }

        // If number is Odd
        else{
            System.out.println(number + " is Odd");
        }

    }
}


/* ===========================================================
Output: 

0 is neither even nor odd

 =========================================================== */