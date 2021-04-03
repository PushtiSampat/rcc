import java.net.*;
import java.util.Calendar;

public class UDP6Server {
    public static void main(String[] args) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        byte[] recieveData = new byte[1024];
        byte[] sendData = new byte[1024];
        int year, month, day;
        String selectedData;
        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(recieveData, recieveData.length);
            serverSocket.receive(receivePacket);
            String clientSentence = new String(receivePacket.getData()).trim();
            InetAddress ipAddress = receivePacket.getAddress();
            int port = receivePacket.getPort();
            try {
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

                selectedData = gage.age(tday, tmonth, tyear, day, month, year);

            } catch (Exception e) {
                selectedData = "Invalid Dates";
            }
            sendData = selectedData.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAddress, port);
            serverSocket.send(sendPacket);
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