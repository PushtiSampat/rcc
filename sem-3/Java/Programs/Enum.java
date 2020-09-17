public class Enum{
    enum WashChoice {cotton, linen, wool, synthetic}

    public static void main(String[] args){
        WashChoice wash = WashChoice.cotton;

        // 1. shirts, 2. sweaters, 3. socks, 4. sheets, 5. pants
        int clothes = 3;

        switch(clothes){
            case 1:
                System.out.println("Washing Shirts");
                wash = WashChoice.cotton;
                break;

            case 2:
                System.out.println("Washing Sweaters");
                wash = WashChoice.wool;
                break;

            case 3:
                System.out.println("Washing socks");
                wash = WashChoice.wool;
                break;
            case 4:
                System.out.println("Washing Sheets");
                wash = WashChoice.linen;
                break;
            case 5:
                System.out.println("Washing Pants");
                wash = WashChoice.synthetic;
                break;
            default:
                System.out.println("Invalid Choice");
        }
    }

}
