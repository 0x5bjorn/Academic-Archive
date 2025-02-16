import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Vertices2 extends JFrame {
	String title = "Vertices2";
	Color background = Color.BLACK;
	
	void draw(Graphics g) {
		int n = 26;
		int w = getWidth();
		int h = getHeight();
		int rad = h / 2;
		
		Color color = new Color(255, 0, 0);
		g.setColor(color);

		for (int i = 0; i < n; ++i) {
			double alp = i * (360.0/n*Math.PI)/180.0;
			int x = (int) (w/2 + Math.cos(alp) * rad);
			int y = (int) (h/2 + Math.sin(alp) * rad);
			int x1 = (int) (w/2 + Math.cos((i+12)*(360.0/n*Math.PI)/180.0) * rad);
			int y1 = (int) (h/2 + Math.sin((i+12)*(360.0/n*Math.PI)/180.0) * rad);
			g.drawLine(w/2, h/2, x, y);
			g.drawLine(x, y, x1, y1);
		}
	}

	public Vertices2() {
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
		new Vertices2();
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
