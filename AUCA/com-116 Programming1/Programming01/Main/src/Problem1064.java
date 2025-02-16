import java.util.*;

public class Problem1064 {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner input = new Scanner(System.in);
		int total = 0;
		double aver = 0;
		int a = 0;
		while (a<6) {
			double n = input.nextDouble();
			if (n>0) {
				++total;
				aver+=n;
			}	
			++a;
		}
		aver/=total;
		System.out.printf("%d valores positivos\n", total);
		System.out.printf("%.1f\n", aver);
	}
}
