 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      02-CLA.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class CLA{
    public static void main(String[] args){

        // Prints length of total arguments
        int argsCount = args.length;
        System.out.println("Total arguments: " + argsCount);
        
        // Iterates over every argument
        for(int i = 0; i < argsCount; i++)
            System.out.println("Argument no " + i + " is: " + args[i]);

    }
}




/* ===========================================================
Output: 

java CLA 10 20 30 40 50

Total arguments: 1
Argument no 0 is: 10

 =========================================================== */
