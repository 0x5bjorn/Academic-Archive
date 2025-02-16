import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class RandomBalls extends JFrame {
	String title = "Lab 05 Problem 04";
	Color background = Color.WHITE;

	Random rand = new Random();

	void draw(Graphics g) {
		final int maxRadius = 70;
		int width = getWidth();
		int height = getHeight();
		
		for (int i = 0; i < 100; ++i) {
			int red = rand.nextInt(256);
			int green = rand.nextInt(256);
			int blue = rand.nextInt(256);
			g.setColor(new Color(red, green, blue));
			
			int radius = rand.nextInt(maxRadius+1);
			int diameter = 2 * radius;

			int x = rand.nextInt(width + 1) - radius;
			int y = rand.nextInt(height + 1) - radius;

			g.fillOval(x, y, diameter, diameter);
		}
	}

	public RandomBalls() {
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
		new RandomBalls();
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
