import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String input = sc.next();
            int baseFrom = sc.nextInt(), baseTo = sc.nextInt();
            BigInteger convert = new BigInteger(input,baseFrom);
            String convertTo = convert.toString(baseTo).toUpperCase();
            if(convertTo.length() > 7) convertTo = "ERROR";
            System.out.println(String.format("%7s",convertTo));
        }
    }
}
