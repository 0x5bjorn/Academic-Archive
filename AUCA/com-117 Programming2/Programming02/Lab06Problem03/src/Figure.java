import java.awt.*;

public abstract class Figure {
	protected int x, y, w, h;
	private boolean isSelected;
	
	public Figure(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public boolean isSelected() {
		return isSelected;
	}
	
	public void move(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
	
	public void setSelected(boolean isSelected) {
		this.isSelected = isSelected;
	}
	
	public abstract void draw(Graphics g);
	
	public abstract boolean contains(int x2, int y2) ;

}
