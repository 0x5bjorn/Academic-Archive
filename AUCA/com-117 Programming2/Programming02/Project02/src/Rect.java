import java.awt.*;

public class Rect extends Figure {
	private int w;
	private int h;
	private int puz;
	private static String n;

	public Rect(int x, int y, int w, int h, int puz) {
		super(x, y);
		this.w = w;
		this.h = h;
		this.puz = puz;
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(Color.BLACK);
		g.fillRoundRect(x, y, w, h, w / 5, h / 5);
		g.setColor(Color.RED);
		g.drawRoundRect(x, y, w, h, w / 5, h / 5);

		if (puz==16) n = " ";
		else n = String.valueOf(puz);
		g.setFont(new Font(n, Font.BOLD, 100));
		FontMetrics fm = g.getFontMetrics();
		int stringWidth = fm.stringWidth(n);
		int stringAscent = fm.getAscent();
		g.drawString(n, x + w/2 - stringWidth / 2, y + h - stringAscent / 2);
	}

	@Override
	public boolean contains(int x, int y) {
		boolean b1 = this.x <= x && x <= this.x + this.w;
		boolean b2 = this.y <= y && y <= this.y + this.h;
		return b1 && b2;
	}
}
