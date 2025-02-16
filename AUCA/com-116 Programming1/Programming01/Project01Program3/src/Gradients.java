import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Gradients extends JFrame {
	String title = "Gradients";
	Color background = Color.BLACK;

	void draw(Graphics g) {
		int w = getWidth();
		int h = getHeight();
		int a = Math.min(w, h) / 8;

		int x1 = w / 14;
		int y1 = h / 10;
		int x2 = x1;
		int y2 = y1 + h / 2 + h / 4;

		for (int i = 0; i < 9; ++i) {
			for (int red = 0; red <= 255; red += 4, x1 += 1, x2 += 1) {
				Color color = new Color(red, 0, 0);
				g.setColor(color);
				g.drawLine(x1, y1, x2, y2);
			}
			for (int red = 255; red >= 0; red -= 4, x1 += 1, x2 += 1) {
				Color color = new Color(red, 0, 0);
				g.setColor(color);
				g.drawLine(x1, y1, x2, y2);
			}
		}
	}

	public Gradients() {
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
		new Gradients();
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
