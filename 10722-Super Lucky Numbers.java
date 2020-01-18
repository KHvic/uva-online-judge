import java.math.BigDecimal;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        int b, n;
        Scanner sc = new Scanner(System.in);
        while(true) {
            b = sc.nextInt();
            n = sc.nextInt();
            if(b==0  && n==0) {
                break;
            }
            BigDecimal isOne = BigDecimal.valueOf(1);
            BigDecimal notOne = BigDecimal.valueOf(b-2);
            // isOne2 = notOne + isOne
            // notOne = notOne + (isOne+notOne)*(b-2)
            for(int i=1;i<n;i++) {
                BigDecimal isOne2 = isOne.add(notOne);
                BigDecimal notOne2 = isOne.add(notOne).multiply(BigDecimal.valueOf(b-2));
                notOne2 = notOne2.add(notOne);
                isOne = isOne2;
                notOne = notOne2;
            }
            BigDecimal sum = isOne.add(notOne);
            System.out.println(sum);
        }
    }
}
