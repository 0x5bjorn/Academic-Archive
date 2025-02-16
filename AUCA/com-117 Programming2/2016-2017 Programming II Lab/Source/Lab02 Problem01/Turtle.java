
public class Turtle {
	
	public static final int RIGHT = 0;
	public static final int DOWN = 1;
	public static final int LEFT = 2;
	public static final int UP = 3;
	
	private int row;
	private int col;
	private int dir;
	private boolean isPenDown;
	private Field field;
	
	public Turtle(int aRow, int aCol, int aDir, boolean anIsPenDown, Field aField) {
		row = aRow;
		col = aCol;
		dir = aDir;
		isPenDown = anIsPenDown;
		field = aField;
	}

	public void penDown() {
		isPenDown = true;
	}

	public void move(int dist) {
		int dr = 0;
		int dc = 0;
		switch (dir) {
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
			if (isPenDown) {
				field.fill(row, col, '*');
			}
			row += dr;
			col += dc;
		}
	}

	public void turnRight() {
		++dir;
		if (dir == 4) {
			dir = 0;
		}
	}

	public void penUp() {
		isPenDown = false;
		
	}

	public void turnLeft() {
		--dir;
		if (dir == -1) {
			dir = 3;
		}
		
	}
	
}
