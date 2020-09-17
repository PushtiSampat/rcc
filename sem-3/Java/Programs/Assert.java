class Assert{
    public static void main(String[] args){
        // java -ea Test
        int value = 18;
        assert value >= 20: "Eligible";

        System.out.println("Value: " + value);
    }
}
