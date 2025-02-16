import java.util.*;

public class ACM {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		String m = null;
		int[] con1 = new int[5];
		for (int i=0; i<con1.length; ++i) {
			con1[i] = input.nextInt();
		}
		for (int i=0; i<con1.length; ++i) {
			int n = input.nextInt();
			if (con1[i]==n) {
				m="N";
				break;
			}
			else 		   m="Y";
		}
		System.out.println(m);
	}
}
