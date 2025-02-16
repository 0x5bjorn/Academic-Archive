import java.util.*;

public class Problem1131 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int grenais = 0;
		int inter = 0;
		int gremio = 0;
		int draw = 0;
		
		int a = input.nextInt();
		int b = input.nextInt();
		System.out.println("Novo grenal (1-sim 2-nao)");
		int c = input.nextInt();
		++grenais;
		if (a>b) {
			++inter;
		}
		else if (a<b) {
			++gremio;
		}
		else {
			++draw;
		}
		while (c==1) {
			a = input.nextInt();
			b = input.nextInt();
			System.out.println("Novo grenal (1-sim 2-nao)");
			c = input.nextInt();
			++grenais;
			if (a>b) {
				++inter;
			}
			else if (a<b) {
				++gremio;
			}
			else {
				++draw;
			}
		}
		if (c==2) {
			System.out.printf("%d grenais\n", grenais);
			System.out.printf("Inter:%d\n", inter);
			System.out.printf("Gremio:%d\n", gremio);
			System.out.printf("Empates:%d\n", draw);
			if (inter>gremio) {
				System.out.println("Inter venceu mais");
			}
			else {
				System.out.println("Gremio venceu mais");
			}
		}
	}
}