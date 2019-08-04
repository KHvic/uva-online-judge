import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            StringBuilder a = new StringBuilder(sc.next());
            StringBuilder b = new StringBuilder(sc.next());
            a.reverse(); b.reverse();
            BigInteger res = new BigInteger(a.toString()).add(new BigInteger(b.toString()));
            a = new StringBuilder(res.toString());
            a.reverse();
            // remove leading zero
            int i=0;
            while(i<a.length()-1 && a.charAt(i) == '0') i++;
            System.out.println(a.toString().substring(i));
        }
    }
}
