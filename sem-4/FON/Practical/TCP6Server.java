import java.io.*;
import java.net.*;
import java.util.Calendar;

public class TCP6Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        int year, month, day;

        ServerSocket welcomeSocket = new ServerSocket(6789);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
                    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());) {
                try {
                    clientSentence = inFromClient.readLine();
                    day = Integer.parseInt(clientSentence.substring(0, clientSentence.indexOf("/")));
                    month = Integer.parseInt(
                            clientSentence.substring(clientSentence.indexOf("/") + 1, clientSentence.lastIndexOf("/")));
                    year = Integer.parseInt(
                            clientSentence.substring(clientSentence.lastIndexOf("/") + 1, clientSentence.length()));

                    Calendar cal = Calendar.getInstance();
                    int tday = cal.get(Calendar.DAY_OF_MONTH);
                    int tmonth = cal.get(Calendar.MONTH) + 1;
                    int tyear = cal.get(Calendar.YEAR);

                    GetAge gage = new GetAge();

                    outToClient.writeBytes(gage.age(tday, tmonth, tyear, day, month, year));

                } catch (Exception e) {
                    outToClient.writeBytes("Invalid Dates");
                }
            }
        }
    }
}

class GetAge {
    private int finalyear;
    private int finalmonth;
    private int finaldays;

    public String age(int tday, int tmonth, int tyear, int day, int month, int year) {
        finalyear = tyear - year - 1;
        finaldays = tday;
        if (tmonth >= month && tday >= day) {
            finalyear++;
            finalmonth = tmonth - month;
            finaldays = tday - day;
        } else {
            finalmonth = ((12 - month) + tmonth) - 1;
        }
        if (finalmonth == 0 && finaldays == 0)
            return "Happy Birthday your Age = " + finalyear + " years " + finalmonth + " months " + finaldays
                    + " days ";
        else
            return "Age = " + finalyear + " years " + finalmonth + " months " + finaldays + " days ";
    }
}
