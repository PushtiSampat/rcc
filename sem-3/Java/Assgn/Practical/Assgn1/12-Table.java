 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      12-Table.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class Table {
    public static void main(String[] args) {

        if(args.length > 1 || args.length < 1){
            System.out.println("Enter only 1 argument");
            System.exit(1);
        }

        int number = Integer.parseInt(args[0]);
        for(int i = 1; i <= 10; i++)
            System.out.println(number + " * " + i + " = " + (number * i));

    }
}


/* ===========================================================
Output: 

10 * 1 = 10
10 * 2 = 20
10 * 3 = 30
10 * 4 = 40
10 * 5 = 50
10 * 6 = 60
10 * 7 = 70
10 * 8 = 80
10 * 9 = 90
10 * 10 = 100

 =========================================================== */