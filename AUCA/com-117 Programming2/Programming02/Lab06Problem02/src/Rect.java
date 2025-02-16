import java.awt.*;

public class Rect extends Figure {
	private int w;
	private int h;
	
	public Rect(int x, int y, int w, int h) {
		super(x,  y);	
		this.w = w;
		this.h = h;
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(Color.RED);
		g.fillRect(x, y, w, h);
		if (isSelected()) {
			g.setColor(Color.WHITE);
			g.drawRect(x, y, w, h);
		}
	}

	@Override
	public boolean contains(int x, int y) {
		boolean b1 = this.x <= x && x <= this.x + this.w;
		boolean b2 = this.y <= y && y <= this.y + this.h;
		return b1 && b2;
	}
	
	@Override
	public String toString() {
		return String.format("Rect: x=%d, y=%d, w=%d, h=%d", x, y, w, h);
	}
}
