import java.util.*;
import java.math.*;
class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
    	Scanner sc = new Scanner(System.in);
    	while(sc.hasNext()){
    		int in;
    		in=sc.nextInt();
    		BigInteger dpMax=BigInteger.valueOf(in);
    		BigInteger dpMin=dpMax, res=dpMax;
    		
    		while(sc.hasNext()){
    			in = sc.nextInt();
    			if(in == -999999) break;
    			
    			BigInteger curVal = BigInteger.valueOf(in);
    			BigInteger productWithMin = curVal.multiply(dpMin);
    			BigInteger productWithMax = curVal.multiply(dpMax);
    			
    			// dpMax = max(cur,productWithMin,productWithMax)
    			// dpMin = min(cur,productWithMin,productWithMax)
    			dpMax = curVal.max(productWithMin).max(productWithMax);
    			dpMin = curVal.min(productWithMin).min(productWithMax);
    			res = res.max(dpMax);
    		}
    		System.out.println(res.toString());
    	}
    }
}
