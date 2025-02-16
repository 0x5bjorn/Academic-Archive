import java.util.*;
public class Lab01Problem01 {

	static final int H = 10;
	static final int W = 10;
	static char[][] field;

	static int turtleRow;
	static int turtleCol;
	static int turtleDir;
	static boolean isTurtlePenDown;
	
	static int id;
	static int dist;
	
	static Scanner scan;

	public static void main(String[] args) {
		
		try {
			run();
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Kid, turtle is out of field");
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
				turtleMove(dist);
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
				dist = scan2.nextInt();
			}
		} catch (InputMismatchException a) {
			throw new Exception(line + ": Incorrect command");
		} catch (NoSuchElementException a) {
			throw new Exception(line + ": Incorrect command");
		}
		if (!(1 <= id && id <= 6 || id == 9)) {
			throw new Exception(line + ": incorrect command");
		}
		if (id == 5 && dist < 0) {
			throw new Exception(line + ": distance can not be negative");
		}
		if (scan2.hasNext()) {
			throw new Exception(line + ": incorrect command");
		}
	}
	
	static void turtleTurnLeft() {
		--turtleDir;
		if (turtleDir == -1) {
			turtleDir = 3;
		}
	}

	static void turtleTurnRight() {
		// turtleDir = (turtleDir+1)%4;
		++turtleDir;
		if (turtleDir == 4) {
			turtleDir = 0;
		}
	}

	static void turtlePenUp() {
		isTurtlePenDown = false;
	}
	
	static void turtlePenDown() {
		isTurtlePenDown = true;
	}

	static void turtleMove(int distance) {
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

		for (int i = 0; i < distance; ++i) {
			if (isTurtlePenDown) {
				field[turtleRow][turtleCol] = '*';
				turtleRow += dr;
				turtleCol += dc;
			}
		}
	}

	static void init() {
		scan = new Scanner(System.in);
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
