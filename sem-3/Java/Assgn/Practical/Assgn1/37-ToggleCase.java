 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      37-ToggleCase.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class ToggleCase{
    public static void main(String[] args){

        // Checking if only 1 argument is passed
        if(args.length > 1 || args.length < 1){
            System.out.println("Enter only 1 string in arg");
            System.exit(1);
        }

        // Reading 1st argument
        String str1 = args[0];

        // Toggling Case
        for(int i = 0; i < str1.length(); i++){
            char c = str1.charAt(i);

            // Cpatital to Small
            if(c >= 65 && c<=90)
                c += 32;

            // Small to Capital
            else if(c >= 97 && c <= 122)
                c -= 32;

            System.out.print(c);
        }
        System.out.println("");
    }
}


/* ===========================================================
Output: 

ToggleCase AjInKyA

aJiNkYa

 =========================================================== */
