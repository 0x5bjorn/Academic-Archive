import java.util.Scanner;

public class Lab04Problem0302 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		ArrayListInt list = new ArrayListInt();
		
		while (scan.hasNextInt()) {
			int x = scan.nextInt();
			list.add(x);
		}
	
		System.out.print("Before reversing: ");
		for (int i = 0; i < list.size(); ++i) {
			System.out.print(" " + list.get(i));
		}
		System.out.println();
		
		// reverse
		int p1 = 0;
		int p2 = list.size() - 1;
		while (p1 < p2) {
			int t = list.get(p1);
			list.set(p1, list.get(p2));
			list.set(p2, t);
			++p1;
			--p2;
		}
		
		System.out.print("After reversing: ");
		for (int i = 0; i < list.size(); ++i) {
			System.out.print(" " + list.get(i));
		}
		System.out.println();
	}

}
