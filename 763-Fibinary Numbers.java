import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        int tc = 1;
        Scanner sc = new Scanner(System.in);
        BigInteger[] fib = new BigInteger[101];
        fib[0] = BigInteger.ONE;
        fib[1] = BigInteger.valueOf(2);
        for(int i=2;i<101;i++)
            fib[i] = fib[i-1].add(fib[i-2]);
        
        while(sc.hasNext()){
            if(tc++ > 1) System.out.println();
            String a = new StringBuilder(sc.next()).reverse().toString();
            String b = new StringBuilder(sc.next()).reverse().toString();
            BigInteger sum = BigInteger.ZERO;
            for(int i=0;i<a.length();i++)
                if(a.charAt(i) == '1')
                    sum = sum.add(fib[i]);
            for(int i=0;i<b.length();i++)
                if(b.charAt(i) == '1')
                    sum = sum.add(fib[i]);
            boolean printed = false;
            // Zeckendorf theorem greedy
            for(int i=100;i>=0;i--)
                if(sum.compareTo(fib[i]) >=0 ){
                    printed = true;
                    sum = sum.subtract(fib[i]);
                    System.out.print("1");
                } else if(printed){
                    System.out.print("0");
                }
            if(!printed) System.out.print("0");
            System.out.println();
        }
    }
}
