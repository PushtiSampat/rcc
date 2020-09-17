 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      27-Factorial.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class Factorial{  
    public static void main(String args[]){  

        int i, ans = 1;
        int number = 5;

        for(i = 1;i <= number; i++)
            ans = ans * i;    

        System.out.println("Factorial of " + number + " is: " + ans);    
    }  
}  


/* ===========================================================
Output: 

Factorial of 5 is: 120

 =========================================================== */