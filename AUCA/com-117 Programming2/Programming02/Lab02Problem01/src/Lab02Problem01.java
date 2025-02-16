import java.util.*;

public class Lab02Problem01 {

	public static void main(String[] args) {
		// Field f = new Field(10, 10);
		// Turtle t = new Turtle(0, 0, Turtle.RIGHT, false, f);
		// t.penDown();
		// t.move(5);
		// t.turnRight();
		// t.move(5);
		// t.turnRight();
		// t.move(5);
		// t.turnRight();
		// t.move(5);
		// t.turnRight();
		// f.show();

//		Scanner scan = new Scanner(System.in);
//		try {
//			UserCommand cmd = new UserCommand(scan);
//			System.out.println("id: " + cmd.getID());
//			if (cmd.getID() == UserCommand.MOVE) {
//				System.out.println("distance: " + cmd.getDistance());
//			}
//		} catch (Exception e) {
//			System.out.println(e.getMessage());
//		}
		try {
			run();
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Kid, turtle is out of field");
		} catch (Exception a) {
			System.out.println(a.getMessage());
		}
	}

	private static void run() throws Exception{
		Field field = new Field(20, 20);
		Turtle turtle = new Turtle(0, 0, Turtle.RIGHT, false, field);
		Scanner scan = new Scanner(System.in);
		
		UserCommand cmd = new UserCommand(scan);
		while (cmd.getID() != UserCommand.EXIT) {
			switch (cmd.getID()) {
			case UserCommand.PEN_UP:
				turtle.penUp();
				break;
			case UserCommand.PEN_DOWN:
				turtle.penDown();
				break;
			case UserCommand.TURN_RIGHT:
				turtle.turnRight();
				break;
			case UserCommand.TURN_LEFT:
				turtle.turnLeft();
				break;
			case UserCommand.MOVE:
				turtle.move(cmd.getDistance());
				break;
			case UserCommand.SHOW:
				field.show();
				break;
			}
			cmd = new UserCommand(scan);
		}
	}
}
