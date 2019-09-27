import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            System.out.println(n+"!");
            BigInteger res = BigInteger.ONE;
            for(int i=2;i<=n;i++){
                res = res.multiply(BigInteger.valueOf(i));
            }
            System.out.println(res);
        }
    }
}
