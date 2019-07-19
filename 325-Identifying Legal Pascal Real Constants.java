import java.util.*;
public class Main {
    public static void main(String args[]) {
        String in;
        Scanner sc = new Scanner(System.in);
        
        while(!(in = sc.next()).equals("*")){
            if(in.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)"))
                System.out.println(in + " is legal.");
            else
                System.out.println(in + " is illegal.");
        }
    }
}
