import java.util.*;

public class FakeTickets {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int n = input.nextInt();
			int m = input.nextInt();
			if (n == 0 && m==0) break;
			find(n, m);
		}
	}

	static void find(int n, int m) {
		int c = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < m; ++i) {
			list.add(input.nextInt());
		}
		HashSet<Integer> l = new HashSet<Integer>();
		for (int i = 0; i < m; ++i) {
			l.add(list.get(i));
		}
		for(int ls : l){
			int s = 0;
			for(int j = 0; j < m; ++j){
				if(ls == list.get(j)){
					++s;
				}
			}
			if(s > 1) ++c;
		}	
		System.out.println(c);
	}
}
