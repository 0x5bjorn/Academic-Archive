import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class ChessBoard extends JFrame {
	String title = "ChessBoard";
	Color background = Color.BLACK;

	Random rand = new Random();

	void draw(Graphics g) {
		int w = getWidth();
		int h = getHeight();
		int a = h - (h / 10 + h / 10);
		int a1 = a / 8;

		int x = w / 4;
		int y = h / 10;

		Color color = new Color(0, 0, 255);
		g.setColor(color);
		g.fillRect(x, y, a, a);

		for (int i = 0; i < 4; ++i) {
			for (int n = 0; n < 4; ++n, x += a1 * 2) {
				Color color1 = new Color(255, 0, 0);
				g.setColor(color1);
				g.fillRect(x, y, a1, a1);
			}
			x -= a1;
			y += a1;
			for (int n = 0; n < 4; ++n, x -= a1 * 2) {
				Color color1 = new Color(255, 0, 0);
				g.setColor(color1);
				g.fillRect(x, y, a1, a1);
			}
			x += a1;
			y += a1;
		}
	}

	public ChessBoard() {
		setTitle(title);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		DrawPanel panel = new DrawPanel();

		panel.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				System.exit(0);
			}
		});

		add(panel);

		setUndecorated(true);
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setVisible(true);
	}

	public static void main(String[] args) {
		new ChessBoard();
	}

	class DrawPanel extends JPanel {
		public DrawPanel() {
			setBackground(background);
			setFocusable(true);
			requestFocusInWindow();
			setDoubleBuffered(true);
		}

		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			draw(g);
		}
	}
}
