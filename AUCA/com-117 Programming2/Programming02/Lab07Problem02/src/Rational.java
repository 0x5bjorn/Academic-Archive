
public class Rational implements MyComparable{
	private int num;
	private int den;

	public Rational(int aNum, int aDen) throws Exception {
		num = aNum;
		den = aDen;

		if (den == 0) {
			throw new Exception("Rational's denominator cannot be zero");
		}

		int d = MyMath.gcd(num, den);

		num /= d;
		den /= d;

		if (den < 0) {
			den *= -1;
			num *= -1;
		}
	}

	@Override
	public String toString() {
		return num + "/" + den;
	}

	public Rational add(Rational b) throws Exception {
		int tnum = num * b.den + den * b.num;
		int tden = den * b.den;
		return new Rational(tnum, tden);
	}

	public Rational subtract(Rational b) throws Exception {
		int tnum = num * b.den - den * b.num;
		int tden = den * b.den;
		return new Rational(tnum, tden);
	}

	public Rational multiply(Rational b) throws Exception {
		int tnum = num * b.num;
		int tden = den * b.den;
		return new Rational(tnum, tden);
	}

	public Rational divide(Rational b) throws Exception {
		int tnum = num * b.den;
		int tden = den * b.num;
		return new Rational(tnum, tden);
	}

	public static Rational parseRational(String line) throws Exception {
		int p = line.indexOf('/');
		if (p == -1) {
			int num = Integer.parseInt(line.trim());
			return new Rational(num, 1);
		}
		int tnum = Integer.parseInt(line.substring(0, p).trim());
		int tden = Integer.parseInt(line.substring(p + 1).trim());

		return new Rational(tnum, tden);
	}
	
	@Override
	public int compareTo(Object other) {
		Rational r = (Rational)other;
		
		return num * r.den - den * r.num;
		
//		int tnum = num * b.den;
//		int tden = den * b.num;
//		if (tnum > tden) 		return 1;
//		else if (tnum == tden)  return 0;
//		else if (tnum < tden) 	return -1;
	}
}
