class LogicalOpTable{
    public static void main(String args[]){
        boolean a,b;
        int p,q;

        a = true; b = true;

        // Setting a and b as numberic
        if(a) p = 1; else p = 0; 
        if(b) q = 1; else q = 0; 

        System.out.println("P\tQ\tAnd\tOR\tXor\tNot\n");

        // ------------------------------------

        System.out.println(p + "\t" + q + "\t");
        System.out.println((p&q) + "\t" + (p|q) + "\t");
        System.out.print((p^q) + "\t");

        if(!a){ System.out.println("1" + "\t");}
        else{ System.out.println("0" + "\t"); }

        System.out.println("");

        // ------------------------------------

        a = true; b = false;
        // Setting a and b as numberic
        if(a) {p = 1;} else {p = 0; }
        if(b) {q = 1;} else {q = 0; }

        System.out.println(p + "\t" + q + "\t");
        System.out.println((p&q) + "\t" + (q|q) + "\t");
        System.out.print((p^q) + "\t");
        if(!a){ System.out.println("1" + "\t");}
        else{ System.out.println("0" + "\t"); }
        System.out.println("");

        // ------------------------------------

        a = false; b = true;
        // Setting a and b as numberic
        if(a) {p = 1;} else {p = 0; }
        if(b) {q = 1;} else {q = 0; }

        System.out.println(p + "\t" + q + "\t");
        System.out.println((p&q) + "\t" + (q|q) + "\t");
        System.out.print((p^q) + "\t");
        if(!a){ System.out.println("1" + "\t");}
        else{ System.out.println("0" + "\t"); }
        System.out.println("");

        // ------------------------------------

        a = false; b = false;
        // Setting a and b as numberic
        if(a) {p = 1;} else {p = 0; }
        if(b) {q = 1;} else {q = 0; }

        System.out.println(p + "\t" + q + "\t");
        System.out.println((p&q) + "\t" + (q|q) + "\t");
        System.out.print((p^q) + "\t");
        if(!a){ System.out.println("1" + "\t");}
        else{ System.out.println("0" + "\t"); }
        
    }
}
