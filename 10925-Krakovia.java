import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc=1;
        while(true){
            int n = sc.nextInt(), f = sc.nextInt();
            if(n==0&&f==0) break;
            BigInteger sum = BigInteger.ZERO;
            for(int i=0;i<n;i++){
                BigInteger beerValue = sc.nextBigInteger();
                sum = sum.add(beerValue);
            }
            BigInteger average = sum.divide(BigInteger.valueOf(f));
            System.out.println("Bill #" + (tc++) + " costs " + sum + ": each friend should pay " + average + "\n");
        }
    }
}
