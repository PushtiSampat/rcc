 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      10-ScopeDemo.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class ScopeDemo {
    public static void main(String args[]) {
        int x = 10;

        if(x == 10){
            int y = 20;

            System.out.println("x and y: " + x + "" + y);
                x = y* 2;
        }

        System.out.println("x is " + x);
    }
}


/* ===========================================================
Output: 

x and y: 1020
x is 40

 =========================================================== */