import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt(), a = sc.nextInt();
            BigInteger aBig = BigInteger.valueOf(a);
            BigInteger res = BigInteger.ZERO;
            for(int i=1;i<=n;i++){
                res = res.add(aBig.pow(i).multiply(BigInteger.valueOf(i)));
            }
            System.out.println(res);
        }
    }
}
