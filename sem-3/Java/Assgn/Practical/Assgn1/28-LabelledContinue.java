 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      28-LabelledContinue.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class Factorial2 {
    public static void main(String[] args) {
        long limit = 20L;
        long factorial = 1L;

        OuterLoop:
        for(long i = 1L; i <= limit; i++){
            factorial = 1;
            for(long j = 2L; j <= i; j++){
                if(i > 10L && i % 2L == 1L)
                    continue OuterLoop;
                factorial *= j;
            }

            System.out.println(i + "! is " + factorial);
        }
    }
}


/* ===========================================================
Output: 

1! is 1
2! is 2
3! is 6
4! is 24
5! is 120
6! is 720
7! is 5040
8! is 40320
9! is 362880
10! is 3628800
12! is 479001600
14! is 87178291200
16! is 20922789888000
18! is 6402373705728000
20! is 2432902008176640000

 =========================================================== */