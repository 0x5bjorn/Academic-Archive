import java.awt.*;

public abstract class Figure {
	protected int x, y, w, h;
	
	public Figure(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public abstract void draw(Graphics g);
	public abstract boolean contains(int x2, int y2) ;

}
