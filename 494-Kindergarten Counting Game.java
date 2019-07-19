import java.util.*;
public class Main {
    public static void main(String args[]) {
        String in;
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            in = sc.nextLine();
            in = in.replaceAll("(^[^a-zA-Z]+)|([^a-zA-Z]+$)", "");
            System.out.println(in.split("[^a-zA-Z]+").length);
        }
    }
}
