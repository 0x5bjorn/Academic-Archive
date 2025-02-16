import java.util.Scanner;

public class ShortAtten {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a = input.nextLine();
		int a1 = Integer.parseInt(a);
		for (int i = 0; i < a1; ++i) {
			int b = input.nextInt();
			String[] n = new String[b];
			String[] at = new String[b];
			for (int j = 0; j < b; ++j){
				n[j] = input.next();
			}
			for (int j = 0; j < b; ++j){
				at[j] = input.next();
			}
			
			double limit = 0.75;
			boolean first = true;
			for (int j = 0; j < b; ++j) {
				int total = at[j].length();
				int att = 0;
				for (int k = 0; k < at[j].length(); ++k) {
					if (at[j].charAt(k) == 'P') {
						++att;
					} else if (at[j].charAt(k) == 'M') {
						--total;
					}
				}
				if((double) att/total < limit){
					if(first){
						System.out.print(n[j]);
						first = false;
					}else{
						System.out.print(" " + n[j]);
					}
				}
			}
			System.out.println();
		}
	}
}