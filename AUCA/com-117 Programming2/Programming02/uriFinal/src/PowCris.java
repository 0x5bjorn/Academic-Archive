import java.util.*;

public class PowCris {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (true) {
			int n = input.nextInt();
			if (n == 0) break;
			int m = 1;
			while(Flav(n,m) != 13){
				++m;
			}
			System.out.println(m);
		}
	}

	static int Flav(int n, int m) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			list.add(i + 1);
		}
		int i = 0;
		list.remove(0);
		while (list.size() > 1) {
			i = (i + m - 1) % list.size();
			list.remove(i);
		}
		return list.get(0);
	}
}