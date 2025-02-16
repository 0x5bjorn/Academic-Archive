import java.util.ArrayList;

public class Lab04Problem0301 {

	public static void main(String[] args) {
		final int N = 10000000;
		
		ArrayListInt lst1 = new ArrayListInt();
		
		long beg1 = System.currentTimeMillis();
		for (int i = 0; i < N; ++i) {
			lst1.add(i);
		}
		long end1 = System.currentTimeMillis();
		
		System.out.println("Our class: " + (end1 - beg1));
		
		ArrayList<Integer> lst2 = new ArrayList<Integer>();
		
		long beg2 = System.currentTimeMillis();
		for (int i = 0; i < N; ++i) {
			lst2.add(i);
		}
		long end2 = System.currentTimeMillis();
		
		System.out.println("ArrayList: " + (end2 - beg2));
	}
}