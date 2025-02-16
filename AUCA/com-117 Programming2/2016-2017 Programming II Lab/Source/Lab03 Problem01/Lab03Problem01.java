import java.util.Scanner;

public class Lab03Problem01 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while (true) {
			String line = null;
			try {
				System.out.print("1st rational (Ctrl-Z for exit): ");
				if (!scan.hasNextLine()) break;
				
				line = scan.nextLine();
				Rational a = Rational.parseRational(line);

				System.out.print("Operation (+, -, *, /): ");
				String op = scan.nextLine();

				System.out.print("2nd rational (Ctrl-Z for exit): ");
				if (!scan.hasNextLine()) break;
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
				System.out.println("Incorrect rational: " + line);
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}

}
