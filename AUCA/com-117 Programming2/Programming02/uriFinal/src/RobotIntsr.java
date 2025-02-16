import java.util.*;

public class RobotIntsr {
	static Scanner input = new Scanner(System.in);
	static int p = 0;
	public static void main(String[] args) {
		String t = input.nextLine();
		for (int i = 0; i < Integer.parseInt(t); ++i) {
			String n = input.nextLine();
			execute(n);
		}
	}

	static void execute(String n) {
		int[] ins = new int[Integer.parseInt(n)];
		for (int j = 0; j < Integer.parseInt(n); ++j) {
			String inst = input.nextLine();
			if 		(inst.equals("LEFT"))  ins[j] = -1;
			else if (inst.equals("RIGHT")) ins[j] = 1;
			else 	ins[j] = ins[Integer.parseInt(inst.substring(8)) - 1];
			p+=ins[j];
		}
		System.out.println(p);
		p=0;
	}
}
