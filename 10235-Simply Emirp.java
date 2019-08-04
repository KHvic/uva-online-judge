import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            BigInteger val = BigInteger.valueOf(n);
            StringBuilder sb = new StringBuilder(String.valueOf(n)).reverse();
            BigInteger reverseVal = new BigInteger(sb.toString());
            System.out.printf("%d is ",n);
            // miller-rabin probabilistic prime testing
            if(!val.isProbablePrime(10))
                System.out.println("not prime.");
            else if(!val.equals(reverseVal) && reverseVal.isProbablePrime(10))
                System.out.println("emirp.");
            else
                System.out.println("prime.");
        }
    }
}
