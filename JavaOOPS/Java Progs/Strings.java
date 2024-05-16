// import java.util.*;
import java.util.Scanner;

public class Strings {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s;
        System.out.print("Enter string: ");
        s = sc.nextLine();
        int c = 0;
        //char ch = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i-1))
                c++;
        }
        System.out.println(c);
    }
}
