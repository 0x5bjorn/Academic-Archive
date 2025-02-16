import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Vertices extends JFrame {
	String title = "Vertices";
	Color background = Color.BLACK;
	
	void draw(Graphics g) {
		int n = 10;
		int w = getWidth();
		int h = getHeight();
		int rad = h / 2 - 10;
		
		Color color = new Color(255, 0, 0);
		g.setColor(color);

		for (int i = 0; i < 2; ++i) {
			double alp = (360.0/n*Math.PI)/180.0;
			int x = (int) (w/2 + Math.cos(alp*i) * rad);
			int y = (int) (h/2 + Math.sin(alp*i) * rad);
			int x1 = (int) (w/2 + Math.cos(alp*(i+1)) * rad);
			int y1 = (int) (h/2 + Math.sin(alp*(i+1)) * rad);
			g.drawLine(w/2, h/2, x, y);
			g.drawLine(x, y, x1, y1);
		}
	}
	
	void drawLines() {
		
	}

	public Vertices() {
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
		new Vertices();
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
