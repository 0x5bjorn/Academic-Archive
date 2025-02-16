import java.util.*;

public class Problem1070 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int n = 0;
		n+=a;
		while (n>=a && n<=(a+11)) {
			n++;
			if (n%2!=0){
				System.out.println(n);
			}
		}
	}
}