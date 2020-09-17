public class Arithmetic_CLA {
    public static void main(String[] args) {

        System.out.println("There are " + args.length + " command line arguments.");

        for (int i = 0; i < args.length; i++)
            System.out.println("arg[" + i + "] = " + args[i]);


        float price = 5.0f;
        System.out.print(price / 2.0);
        System.out.print("  " + 5 % 2);
        System.out.print("  " + 4 / 2);
        System.out.print("  " + 4 % 2);

    }
}
