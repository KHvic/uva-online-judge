import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(true){
            BigInteger n = sc.nextBigInteger();
            if(n.compareTo(BigInteger.ZERO) == 0) break;
            if(n.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO) == 0)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
