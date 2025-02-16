public class Problem1097 {

	public static void main(String[] args) {
		for (int i=1, j=7, a=5; i<10; i+=2, j+=5, a+=2) {
			while (j>=a) {
				System.out.printf("I=%d J=%d\n", i, j);
				--j;
			}
		}
	}
}
