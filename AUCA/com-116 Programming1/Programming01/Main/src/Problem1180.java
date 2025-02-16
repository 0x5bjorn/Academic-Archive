import java.util.*;

public class Problem1180 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int pos = 0;
		int min = 0;
		int n = input.nextInt();
		int[] list = new int[n];
		for (int i=0; i<list.length; ++i) {
			list[i] = input.nextInt();
			if (min>list[i]) {
				min=list[i];
				pos=i;
			}
		}
		System.out.printf("Menor valor: %d\n", min);
		System.out.printf("Posicao: %d\n", pos);
	}
}
