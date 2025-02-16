import java.util.*;

public class Lab03Problem01 {

	public static void main(String[] args) {
		while (true) {
			String line = null;
			try {
				Scanner scan = new Scanner(System.in);

				System.out.print("1st rational: ");
				if (!scan.hasNextLine())
					break;
				line = scan.nextLine();
				Rational a = Rational.parseRational(line);

				System.out.print("operation (+, -, *, /): ");
				String op = scan.nextLine().trim();

				System.out.print("2nd rational: ");
				if (!scan.hasNextLine())
					break;
				line = scan.nextLine();
				Rational b = Rational.parseRational(line);

				switch (op) {
				case "+":
					System.out.println(a + " + " + b + " = " + a.add(b));
					break;
				case "-":
					System.out.println(a + " - " + b + " = " + a.subtract(b));
					break;
				case "*":
					System.out.println(a + " * " + b + " = " + a.multiply(b));
					break;
				case "/":
					System.out.println(a + " / " + b + " = " + a.divide(b));
					break;
				default:
					System.out.println("Unsupported operation: " + op);
					break;
				}

			} catch (NumberFormatException e) {
				System.out.print("Incorrect rational: " + line);
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
	}
}