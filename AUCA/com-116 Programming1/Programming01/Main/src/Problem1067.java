import java.util.*;

public class Problem1067 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int n = 0;
		if (a>0 && a<1001) {
			while (n<a){
				++n;
				if (n%2!=0){
					System.out.println(n);
				}	
			}
		}
	}
}
