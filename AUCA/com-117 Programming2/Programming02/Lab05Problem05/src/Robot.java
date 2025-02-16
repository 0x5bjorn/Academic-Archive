
public class Robot {
	private int row;
	private int col;
	
	public Robot(int aRow, int aCol) {
		row = aRow;
		col = aCol;
	}
	
	public int getCol() {
		return col;
	}
	
	public int getRow() {
		return row;
	}

	public void moveUp() {
		if (row > 0) {
			--row;
		}
	}
	public void moveDown() {
		if (row < 7) {
			++row;
		}
	}
	public void moveLeft() {
		if (col > 0) {
			--col;
		}
	}
	public void moveRight() {
		if (col < 7) {
			++col;
		}
	}
}
