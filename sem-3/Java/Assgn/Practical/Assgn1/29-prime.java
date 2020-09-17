 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      29-prime.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class Prime{
    public static void main(String[] args){
        long num = 67280421310721L;

        if(num > 2 && num%2 == 0){
            System.out.println(num + " is not prime");
            System.exit(0);
        }

        int sqrt = (int)Math.sqrt(num) + 1;

        for(int i = 3; i < sqrt; i+=2){
            if(num % i == 0){
                System.out.println(num + " is not prime");
                System.exit(0);
            }
        }
        System.out.println(num + " is prime");
    }
}


/* ===========================================================
Output: 

67280421310721 is prime

 =========================================================== */