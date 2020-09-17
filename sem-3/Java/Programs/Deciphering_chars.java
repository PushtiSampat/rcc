public class Deciphering_chars{
    public static void main(String[] args){
        char symbol = (char)(128.0 * Math.random());
        System.out.println(symbol);

        if(symbol >= 'A'){
            if(symbol <= 'Z') {
                System.out.println("Capital: " + symbol);
            }
            else {
                if (symbol >= 'a'){
                    if(symbol <= 'z'){
                        System.out.println("Small: " + symbol);
                    }
                    else{
                        System.out.println("Code is Greater but aint a letter");
                    }
                }
            }
        }
        else {
            System.out.println("The Code is less than A and not a letter");
        }
    }
}
