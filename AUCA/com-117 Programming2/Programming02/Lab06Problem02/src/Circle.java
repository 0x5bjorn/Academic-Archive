import java.awt.*;

public class Circle extends Figure {

	private int r;

	public Circle(int x, int y, int r) {
		super(x, y);
		this.r = r;
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(Color.YELLOW);
		g.fillOval(x - r, y - r, r * 2, r * 2);
		if (isSelected()) {
			g.setColor(Color.WHITE);
			g.drawOval(x - r, y - r, 2 * r, 2 * r);
		}
	}

	@Override
	public boolean contains(int x, int y) {
		int dx = this.x - x;
		int dy = this.y - y;
		return dx * dx + dy * dy <= r * r;
	}

	@Override
	public String toString() {
		return String.format("Circle: x=%d, y=%d, r=%d", x, y, r);
	}

}
