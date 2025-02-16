import java.util.*;

public class FAQ {
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		while (true) {
			int n = input.nextInt();
			int k = input.nextInt();
			if (n==0 && k==0) break;
			
			ArrayList<Integer> list = new ArrayList<>();
			for (int i = 0; i<n; ++i) {
				list.add(input.nextInt());
			}
			identify(n, k, list);
		}
	}

	private static void identify(int n, int k, ArrayList<Integer> list) {
		HashSet<Integer> count = new HashSet<>();
		int res = 0;
		for (int i = 0; i<list.size(); ++i) {
			count.add(list.get(i));
		}
		for (Integer i : count) {
			int c = 0;
			for (int j = 0; j<list.size(); ++j) {
				if (i == list.get(j)) c++;
			}
			if (c>=k) res++;
		}
		System.out.println(res);
	}
}
