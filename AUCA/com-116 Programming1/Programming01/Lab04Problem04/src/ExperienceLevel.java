import java.util.*;

public class ExperienceLevel {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("complexity level? ");
		int lvl = input.nextInt();
		if (lvl>=4 && lvl<=5) {
			System.out.println("You are a pro gamer.");
		}
		else if (lvl>=2 && lvl<=3) {
			System.out.println("You are an experienced gamer.");
		}
		else if (lvl==1) {
			System.out.println("You are a beginner.");
		}
		else if (lvl==0) {
			System.out.println("You are a total newbie.");
		}
	}
}
