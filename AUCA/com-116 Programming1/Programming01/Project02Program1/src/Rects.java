import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Rects extends JFrame {
	String title = "Rects";
	Color background = Color.BLACK;
	int delay = 10;

	int a = 500;
	int red1 = 0;
	int dr = 3;

	int x1, y1;

	int x2, y2;

	void start() {
		int w = getWidth();
		int h = getHeight();

		x1 = w / 10;
		y1 = h / 6;

		x2 = w / 10 + w / 2;
		y2 = h / 6;
	}

	void update() {
		if (red1 + dr == 255) {
			dr = -dr;
		} else if (red1 + dr == 0) {
			dr = -dr;
		} else {
			red1 += dr;
		}
	}

	void draw(Graphics g) {
		Color rect1 = new Color(red1, 0, 0);
		g.setColor(rect1);
		g.fillRect(x1, y1, a, a);

		Color rect2 = new Color(255 - red1, 0, 0);
		g.setColor(rect2);
		g.fillRect(x2, y2, a, a);
	}

	public Rects() {
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

		javax.swing.Timer timer = new javax.swing.Timer(delay, new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				update();
				repaint();
			}
		});

		setUndecorated(true);
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setVisible(true);

		start();

		timer.start();
	}

	public static void main(String[] args) {
		new Rects();
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
