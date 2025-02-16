import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Spiral extends JFrame {
	String title = "Spiral";
	Color background = Color.BLACK;

	Random rand = new Random();

	void draw(Graphics g) {
		int w = getWidth();
		int h = getHeight();

		int x = w/2;
		int y = h/2;
		
		Color color = new Color(255, 0, 0);
		g.setColor(color);

		for (int i = 0; i < 1200; ++i) {
			int a = i/3;
			double alpha = i*360/60.0*Math.PI/180;
			int x1 = (int) (w/2 + Math.cos(alpha) * a);
			int y1 = (int) (h/2 - Math.sin(alpha) * a);
			g.drawLine(x, y, x1, y1);
			x=x1;
			y=y1;
		}
	}

	public Spiral() {
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
		new Spiral();
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
