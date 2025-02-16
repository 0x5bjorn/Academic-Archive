import java.util.*;

public class UserCommand {
	public static final int PEN_UP = 1;
	public static final int PEN_DOWN = 2;
	public static final int TURN_LEFT = 3;
	public static final int TURN_RIGHT = 4;
	public static final int MOVE = 5;
	public static final int SHOW = 6;
	public static final int EXIT = 9;
	
	private int id;
	private int distance;
	
	public UserCommand(Scanner scan) throws Exception {
		String line = scan.nextLine();
		
		Scanner scan2 = new Scanner(line);
		
		try {
			id = scan2.nextInt();
			if (id == MOVE) {
				distance = scan2.nextInt();
			}
		} catch (NoSuchElementException e) {
			throw new Exception(line + ": incorrect command");
		}
		
		if (!(PEN_UP <= id && id <= SHOW || id == EXIT)) {
			throw new Exception(line + ": incorrect command");
		} 
		
		if (id == MOVE && distance < 0) {
			throw new Exception(line + ": distance cannot be negative");
		}
		
		if(scan2.hasNext()) {
			throw new Exception(line + ": incorrect command");
		}
	}
	
	public int getID() {
		return id;
	}
	
	public int getDistance() {
		return distance;
	}
}
