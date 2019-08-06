import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        BigInteger seq[] = new BigInteger[1001];
        seq[0] = BigInteger.valueOf(1);
        seq[1] = BigInteger.valueOf(2);
        for(int i=2;i<1001;i++)
            seq[i] = seq[i-1].add(seq[i-2]);
        
        while(sc.hasNext()){
            int n = sc.nextInt();
            System.out.println(seq[n]);
        }
    }
}
