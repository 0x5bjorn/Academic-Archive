import java.util.*;

public class Problem1114 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int pass = 2002;
		int a = input.nextInt();
		while (a != pass) {
			if (a != pass) {
				System.out.println("Senha Invalida");
			} 
			a = input.nextInt();
		}
		if (a == pass) {
			System.out.println("Acesso Permitido");
		}
	}
}
