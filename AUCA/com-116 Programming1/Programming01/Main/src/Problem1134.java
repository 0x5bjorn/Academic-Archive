import java.util.*;

public class Problem1134 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int alc = 0;
		int gas = 0;
		int dies = 0;
		while (n!=4) {
			if (n==1) {
				++alc;
			}
			else if (n==2) {
				++gas;
			}
			else if (n==3) {
				++dies;
			}
			n = input.nextInt();
		}
		if (n==4) {
			System.out.println("MUITO OBRIGADO");
			System.out.printf("Alcool: %d\n", alc);
			System.out.printf("Gasolina: %d\n", gas);
			System.out.printf("Diesel: %d\n", dies);
		}
	}
}
