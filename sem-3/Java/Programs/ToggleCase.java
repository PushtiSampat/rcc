public class ToggleCase{
    public static void main(String[] args){
        String str1 = args[0];
        System.out.println(str1);
        for(int i = 0; i < str1.length(); i++){
            char c = str1.charAt(i);
            if(c >= 65 && c<=90){
                c += 32;
            }
            else if(c >= 97 && c <= 122){
                c -= 32;
            }
            System.out.print(c);
        }
    }
}
