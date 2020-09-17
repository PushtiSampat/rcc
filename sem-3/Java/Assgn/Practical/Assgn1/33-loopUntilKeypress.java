 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      33-loopUntilKeypress.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 class ForTest {
    public static void main(String args[]) throws java.io.IOException {
        int i;
        System.out.println("Press small \"a\" to stop.");

        for(i = 0; (char) System.in.read() != 'a'; i++)
            System.out.println("\"a\" not pressed. Press \"a\" ");
    }
}

 /* ===========================================================
Press small "a" to stop.
q
"a" not pressed. Press "a" 
"a" not pressed. Press "a" 
w
"a" not pressed. Press "a" 
"a" not pressed. Press "a" 
a

* ========================================================== */  
