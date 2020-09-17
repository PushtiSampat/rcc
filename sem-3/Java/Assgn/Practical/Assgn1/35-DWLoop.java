 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      35-DWLoop.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 // Demonstrate the do-while loop.
class DWDemo {
    public static void main(String args[])
            throws java.io.IOException {
            char ch;
            do {
                System.out.print ("Press a key followed by ENTER: ");
                ch = (char) System.in.read();
            } while(ch != 'q');
    }
}

/* ===========================================================
 * Output:
Press a key followed by ENTER: qw

* ========================================================== */  
