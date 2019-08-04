import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();
        while(t-- > 0){
            BigInteger numerator = sc.nextBigInteger();
            sc.next();
            BigInteger denominator = sc.nextBigInteger();
            BigInteger gcd = numerator.gcd(denominator);
            numerator = numerator.divide(gcd);
            denominator = denominator.divide(gcd);
            System.out.println(numerator + " / " + denominator);
        }
    }
}
