import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Segments extends JFrame {
	String title = "Segments";
	Color background = Color.BLACK;

	void draw(Graphics g) {
		int w = getWidth();
		int h = getHeight();
		int a = h - 20;
		double ratio = 0;
		double ratio1 = 0.2;

		int x = w/4;
		int y = 10;
		
		int x1 = w/4;
		int y1 = 10;
				
		for (int i = 0; i < 10; ++i) {
			drawRect(g, a, x, y, x1, y1, Color.RED);
			x = (int) (x + Math.cos(ratio) * a/5);
			y = (int) (y + Math.sin(ratio) * a/5);
			
			ratio+=ratio1;
			a-=a/5;
			x1=x;
			y1=y;
		}
	}
	
	void drawRect(Graphics g, int a, int X1, int Y1, int X2, int Y2, Color c) {
		int x1 = X1;
		int y1 = Y1;
		
		int x2 = X2+a;
		int y2 = Y2;
		
		int x3 = X1+a;
		int y3 = Y1+a;
		
		int x4 = X2;
		int y4 = Y2+a;
		
		g.setColor(c);
		g.drawLine(x1, y1, x2, y2);
		g.drawLine(x2, y2, x3, y3);
		g.drawLine(x3, y3, x4, y4);
		g.drawLine(x4, y4, x1, y1);
	}

	public Segments() {
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
		new Segments();
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
