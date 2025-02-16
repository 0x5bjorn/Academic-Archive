import java.util.*;

public class Problem1096 {

	public static void main(String[] args) {
		for (int i=1; i<10; i+=2) {
			int j = 7;
			while (j>4) {
				System.out.printf("I=%d J=%d\n", i, j);
				--j;
			}
		}
	}
}
