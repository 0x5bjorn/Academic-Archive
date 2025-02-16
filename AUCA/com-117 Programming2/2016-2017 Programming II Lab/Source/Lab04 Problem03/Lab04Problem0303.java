import java.util.Scanner;

public class Lab04Problem0303 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		ArrayListInt list = new ArrayListInt();
		
		while (scan.hasNextInt()) {
			int x = scan.nextInt();
			list.add(x);
		}
	
		// insert 0 before each even element
		int i = 0;
		while (i < list.size()) {
			if (list.get(i) % 2 == 0) {
				list.add(i, 0);
				i += 2;
			} else {
				++i;
			}
		}
		
		for (int j = 0; j < list.size(); ++j) {
			System.out.print(" " + list.get(j));
		}
		System.out.println();
		
		// remove all odd elements
		i = 0;
		while (i < list.size()) {
			if (list.get(i) % 2 != 0) {
				list.remove(i);
			} else {
				++i;
			}
		}
		
		for (int j = 0; j < list.size(); ++j) {
			System.out.print(" " + list.get(j));
		}
		System.out.println();	}

}
