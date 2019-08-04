import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String from = sc.next(), to = sc.next();
            boolean found = false;
            for(int baseFrom=2;baseFrom<=36&&!found;baseFrom++)
                for(int baseTo=2;baseTo<=36&&!found;baseTo++){
                    try{
                        BigInteger newBase = new BigInteger(from,baseFrom);
                        String convert = newBase.toString(baseTo).toUpperCase();
                        if(convert.equals(to)){
                            found = true;
                            System.out.println(from + " (base " + baseFrom + ") = " + to + " (base " + baseTo + ")");
                        }
                    } catch (Exception e){}
                }
            if(!found)
                System.out.println(from + " is not equal to " + to + " in any base 2..36");
        }
    }
}
