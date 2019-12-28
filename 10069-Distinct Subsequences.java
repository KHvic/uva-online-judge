import java.math.BigDecimal;
import java.util.*;

class Main  {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc;
        tc = sc.nextInt();
        for(int t=0;t<tc;t++){
            String str, sub;
            str = sc.next();
            sub = sc.next();
            BigDecimal[] dp = new BigDecimal[str.length()+1];
            Arrays.fill(dp, BigDecimal.valueOf(1));
            for(int i=0;i<sub.length();i++){
                char c1=sub.charAt(i);
                BigDecimal[] dpNext = new BigDecimal[str.length()+1];
                dpNext[0] = BigDecimal.valueOf(0);
                for(int j=0;j<str.length();j++){
                    char c2=str.charAt(j);
                    dpNext[j+1] = BigDecimal.valueOf(0);
                    if(c1 == c2) {
                        dpNext[j+1] = dpNext[j+1].add(dp[j]);
                    }
                    dpNext[j+1] = dpNext[j+1].add(dpNext[j]);
                }
                dp = dpNext;
            }
            System.out.println(dp[str.length()]);
        }
    }
}
