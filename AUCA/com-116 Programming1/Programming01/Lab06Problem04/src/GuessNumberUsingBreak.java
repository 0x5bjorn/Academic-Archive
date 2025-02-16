import java.util.*;

public class GuessNumberUsingBreak {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Random rand = new Random();
		int n = rand.nextInt(101);
		System.out.println("Guess a magic number between 0 and 100");
		while (true) {
			System.out.print("Enter your guess: ");
			int g = input.nextInt();
			if (g==n) {
				System.out.printf("Yes, the number is %d\n", n);
				break;
			} else if (g>n) {
				System.out.println("Your guess is too high");
			} else {
				System.out.println("Your guess is too low");
			}
		}
	}
}
