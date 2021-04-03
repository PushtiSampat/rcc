import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;

public class TCP8Server {
    public static void main(String[] args) throws IOException {
        ServerSocket welcomeSocket = new ServerSocket(6789);
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
            String ip = connectionSocket.getInetAddress().toString();
            String ipAddress = ip.substring(1, ip.length());
            System.out.println("Request from client: " + ipAddress);
            String response = "Your IP Address is " + ipAddress + ", ";
            response += IPAddress.getIPClass(new IPAddress(ipAddress));
            outToClient.writeBytes(response + "\n");
        }
    }
}

public class IPAddress implements Comparable<IPAddress> {
    int a, b, c, d;

    IPAddress(String ip) {
        if (isValid(ip))
            parse(ip);
        else {
            a = b = c = d = 0;
        }
    }

    private void parse(String ip) {
        int[] data = Arrays.stream(ip.split("[.]")).mapToInt(Integer::parseInt).toArray();
        a = data[0];
        b = data[1];
        c = data[2];
        d = data[3];
    }

    public static boolean isValid(String ip) {
        String[] data = ip.split("[.]");
        if (data.length < 4 || data.length > 4)
            return false;

        return Arrays.stream(data).allMatch(value -> {
            int val = Integer.parseInt(value);
            return (val >= 0 && val < 256);
        });
    }

    public static String getIPClass(IPAddress ip) {
        if (ip.a >= 0 && ip.a < 128)
            return "Class A";
        if (ip.a >= 128 && ip.a < 192)
            return "Class B";
        if (ip.a >= 192 && ip.a < 224)
            return "Class C";
        if (ip.a >= 224 && ip.a < 240)
            return "Class D";
        return "Class E";
    }

    public static boolean isSpecial(IPAddress ip) {
        if (ip.compareTo(new IPAddress("0.0.0.0")) >= 0 && ip.compareTo(new IPAddress("0.255.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("10.0.0.0")) >= 0 && ip.compareTo(new IPAddress("10.255.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("100.64.0.0")) >= 0 && ip.compareTo(new IPAddress("100.127.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("127.0.0.0")) >= 0 && ip.compareTo(new IPAddress("127.255.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("169.254.0.0")) >= 0 && ip.compareTo(new IPAddress("169.254.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("172.16.0.0")) >= 0 && ip.compareTo(new IPAddress("172.31.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("192.0.0.0")) >= 0 && ip.compareTo(new IPAddress("192.0.0.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("192.0.2.0")) >= 0 && ip.compareTo(new IPAddress("192.0.2.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("192.88.99.0")) >= 0 && ip.compareTo(new IPAddress("192.88.99.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("192.168.0.0")) >= 0 && ip.compareTo(new IPAddress("192.168.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("198.18.0.0")) >= 0 && ip.compareTo(new IPAddress("198.19.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("198.51.100.0")) >= 0 && ip.compareTo(new IPAddress("198.51.100.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("203.0.113.0")) >= 0 && ip.compareTo(new IPAddress("203.0.113.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("224.0.0.0")) >= 0 && ip.compareTo(new IPAddress("239.255.255.255")) <= 0)
            return true;
        if (ip.compareTo(new IPAddress("240.0.0.0")) >= 0 && ip.compareTo(new IPAddress("255.255.255.255")) <= 0)
            return true;
        return false;
    }

    @Override
    public int compareTo(IPAddress anotherIP) {
        if (a > anotherIP.a)
            return 1;
        else if (a < anotherIP.a)
            return -1;
        else {
            if (b > anotherIP.b)
                return 1;
            else if (b < anotherIP.b)
                return -1;
            else {
                if (c > anotherIP.c)
                    return 1;
                else if (c < anotherIP.c)
                    return -1;
                else {
                    if (d > anotherIP.d)
                        return 1;
                    else if (d < anotherIP.d)
                        return -1;
                    else
                        return 0;
                }
            }
        }
    }

    @Override
    public String toString() {
        return a + "." + b + "." + c + "." + d;
    }
}