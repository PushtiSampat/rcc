public class JavaOperators_Bit{
    public static void main(String[] args){

        // Bitwise Operators

        int a = 65;  // 100 000 1
        int b = 12;  // 000 110 0

        System.out.println(a & b);  //000 000 0
        System.out.println(a | b);  //100 110 1
        System.out.println(a ^ b);  //100 110 1
        System.out.println(~a);     //111 001 0

        System.out.println();

        // Bit Shift
        int c = -10;
        var d = -10L;
        System.out.println(c << 2);
        System.out.println(c >> 2);
        System.out.println(c >>> 2);  // Unsigned

        System.out.println();
        System.out.println(d << 2);
        System.out.println(d >> 2);
        System.out.println(d >>> 2);  // Unsigned Right Shift
        // There is no unsigned Left Shift
    }
}
