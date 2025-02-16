import java.util.*;

public class NumberFreq {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		int t = input.nextInt();
		freq(t);
	}

	private static void freq(int t) {
		ArrayList<Integer> cases = new ArrayList<>();
		ArrayList<Integer> numb = new ArrayList<>();
		ArrayList<Integer> count = new ArrayList<>();
		
		for (int i = 0; i < t; ++i) {
			cases.add(input.nextInt());
		}
		Collections.sort(cases);
		
		for (int i = 0; i < cases.size(); ++i){
			int c = 1;
			int s = 0;
			for(int j = i+1; j < cases.size(); ++j){
				if(cases.get(i)==cases.get(j)){
					++c;
				}
			}
			numb.add(cases.get(i));
			count.add(c);
			i+=c-1;
		}
		for (int k = 0; k < count.size(); ++k){
			System.out.printf("%d aparece %d vez(es)\n", numb.get(k), count.get(k));
		}
	}
}

//import java.util.*;
//
//public class Main {
//	static Scanner input = new Scanner(System.in);
//
//	public static void main(String[] args) {
//		int t = input.nextInt();
//		int[] count = new int[2000];
//		freq(t, count);
//	}
//
//	private static void freq(int t, int[] count) {
//		int[] n = new int[t];
//		for (int i = 0; i < t; ++i) {
//			n[i] = input.nextInt();
//			for (int j = 0; j < count.length; ++j) {
//				if (n[i] == j) {
//					++count[j];
//				}
//			}
//		}
//		Arrays.sort(n);
//		for (int i = 0; i < n.length; ++i) {
//			if (i > 0) {
//				while (n[i] == n[i - 1]) {
//					++i;
//				}
//				System.out.printf("%d aparece %d vez(es)\n", n[i], count[n[i]]);
//			} else {
//				System.out.printf("%d aparece %d vez(es)\n", n[i], count[n[i]]);
//			}
//		}
//	}
//}

