import java.util.*;

public class Problem1172 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		 int[] list = new int[10];
		 for (int i=0; i<list.length; ++i) {
			 int a = input.nextInt();
			 if (a>0) {	
				 System.out.printf("X[%d] = %d\n", i, a);
			 } else {
				 System.out.printf("X[%d] = 1\n", i);
			 }
		 }
	}
}
