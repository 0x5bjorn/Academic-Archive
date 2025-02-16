import java.util.*;

public class DangerousComparison {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		double d = 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		d += 0.1;
		System.out.println(d);
		if (Math.abs(d-1.0)<1E-10) {
			System.out.println("Equal");
		}
		else {
			System.out.println("Not equal");
		}
	}
}
