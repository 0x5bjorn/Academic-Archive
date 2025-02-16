import java.util.*;

public class Colision {
	static Scanner input = new Scanner(System.in);
	static int p = 0;

	public static void main(String[] args) {
		int t = input.nextInt();
		for (int i = 0; i < t; ++i) {
			int[] Rect = new int[8];
			int[] Robot = new int[2];
			for (int j = 0; j < 8; ++j) Rect[j] = input.nextInt();
			for (int j = 0; j < 2; ++j) Robot[j] = input.nextInt();
			check(Rect, Robot);
		}
	}

	private static void check(int[] Rect, int[] Robot) {
		if (Robot[0] >= Rect[0] && Robot[0] <= Rect[2]) {
			if (Robot[1] >= Rect[1] && Robot[1] <= Rect[7]) {
				System.out.println(1);
			} else System.out.println(0);
		} else System.out.println(0);
	}
}