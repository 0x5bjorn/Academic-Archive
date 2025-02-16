import java.util.*;

public class Lab01Problem01 {
	static final int H = 20;
	static final int W = 20;

	static char[][] field;

	static int turtleRow;
	static int turtleCol;
	static int turtleDir;
	static boolean isTurtlePenDown;

	static int id;
	static int distance;
	
	static Scanner scan;
	
	public static void main(String[] args) {
		try {
			run();
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Kid, turtle is out of the field");
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

	static void run() throws Exception {
		init();
		readUserCommand();
		while (id != 9) {
			switch (id) {
			case 1:
				turtlePenUp();
				break;
			case 2:
				turtlePenDown();
				break;
			case 3:
				turtleTurnRight();
				break;
			case 4:
				turtleTurnLeft();
				break;
			case 5:
				turtleMove(distance);
				break;
			case 6:
				showField();
				break;
			}
			readUserCommand();
		}
	}
	
	static void readUserCommand() throws Exception {
		String line = scan.nextLine();
		
		Scanner scan2 = new Scanner(line);
		
		try {
			id = scan2.nextInt();
			if (id == 5) {
				distance = scan2.nextInt();
			}
		} catch (InputMismatchException e) {
			throw new Exception(line + ": incorrect command");
		} catch (NoSuchElementException e) {
			throw new Exception(line + ": incorrect command");
		}
		
		if (!(1 <= id && id <= 6 || id == 9)) {
			throw new Exception(line + ": incorrect command");
		} 
		
		if (id == 5 && distance < 0) {
			throw new Exception(line + ": distance cannot be negative");
		}
		
		if(scan2.hasNext()) {
			throw new Exception(line + ": incorrect command");
		}
	}

	static void turtleTurnLeft() {
		--turtleDir;
		if (turtleDir == -1) {
			turtleDir = 3;
		}
	}

	static void turtlePenUp() {
		isTurtlePenDown = false;
	}
	

	static void turtleMove(int dist) {
		int dr = 0;
		int dc = 0;
		switch (turtleDir) {
		case 0:
			dc = 1;
			break;
		case 1:
			dr = 1;
			break;
		case 2:
			dc = -1;
			break;
		case 3:
			dr = -1;
			break;
		}

		for (int i = 0; i < dist; ++i) {
			if (isTurtlePenDown) {
				field[turtleRow][turtleCol] = '*';
			}
			turtleRow += dr;
			turtleCol += dc;
		}

	}

	static void turtleTurnRight() {
		// turtleDir = (turtleDir + 1) % 4;
		++turtleDir;
		if (turtleDir == 4) {
			turtleDir = 0;
		}
	}

	static void turtlePenDown() {
		isTurtlePenDown = true;
	}

	static void init() {
		turtleRow = 0;
		turtleCol = 0;
		turtleDir = 0;
		isTurtlePenDown = false;

		field = new char[H][W];

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				field[i][j] = '.';
			}
		}
		
		scan = new Scanner(System.in);
	}

	static void showField() {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				System.out.print(field[i][j]);
			}
			System.out.println();
		}
	}

}
