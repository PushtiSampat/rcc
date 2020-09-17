public class Array {
    public static void main(String[] args) {
        double[] myList = {1.9, 2.9, 3.4, 3.5};

        // Print
        for(int i = 0; i < myList.length; i++){
            System.out.println(myList[i] + "  ");
        }

        // Adding All Elements
        double total = 0;
        for(int i = 0; i < myList.length; i++){
            total +=  myList[i];
        }
        System.out.println("Total: " + total);

        // Fetching Max
        double max = myList[0];
        for(int i = 1; i < myList.length; i++){
            if (myList[i] >  max){
                max = myList[i];
            }
        }
        System.out.println("Max: " + max);

    }
}
