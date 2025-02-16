
public class MyMath {

	public static int gcd(int a, int b) throws Exception {
		if (a == 0 && b == 0) {
			throw new Exception("GCD(0,0) is not defined");
		}
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		
		a = Math.abs(a);
		b = Math.abs(b);
		
		int r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}
}
