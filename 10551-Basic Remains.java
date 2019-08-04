import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int base = sc.nextInt();
            if(base == 0) break;
            BigInteger p = new BigInteger(sc.next(),base); // convert base x string to base 10
            BigInteger m = new BigInteger(sc.next(),base);
            p = p.mod(m);
            System.out.println(p.toString(base)); // output as base x
        }
    }
}
