import java.util.*;

public class SeasonName2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("month? ");
		int num = input.nextInt();
		switch (num) {
		case 12: case 1: case 2: 
			System.out.println("winter");
			break;
		case 3: case 4: case 5: 
			System.out.println("spring");
			break;
		case 6: case 7: case 8: 
			System.out.println("summer");
			break;
		case 9: case 10: case 11: 
			System.out.println("autumn");
			break;
		}
	}
}
