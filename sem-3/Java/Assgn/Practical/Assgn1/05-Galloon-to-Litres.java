 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      05-Galloon-to-Litres.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class GalloonToLitres{
    public static void main(String[] args){

        // Value of Galloon
        double galloon = 85.12;

        // Converting Galloon to Litres
        double litres = galloon * 3.78541;

        // Printing Solution
        System.out.print(galloon + " Galloon/s =  ");

        // Setting Precision to 2 digits after decimal
        System.out.println(String.format(" %.2f", litres));
    }
}




/* ===========================================================
Output: 

85.12 Galloon/s =   322.21

 =========================================================== */