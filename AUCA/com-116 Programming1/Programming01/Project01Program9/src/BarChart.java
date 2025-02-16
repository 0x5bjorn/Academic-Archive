import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class BarChart extends JFrame {
	String title = "BarChart";
	Color background = Color.BLACK;

	void draw(Graphics g) {
		int w = getWidth();
		int h = getHeight();
		Random rnd = new Random();
		
		int a1 = w/12;
		int a2 = rnd.nextInt(h-h/6);
		int rX = w/12;
		int rY = h-h/6;
		
		int x = w/12;
		int y = h/12;
		
		int x1 = w/12;
		int y1 = h-h/6;
				
		int x2 = w-w/12;
		int y2 = h-h/6;
		
		g.setColor(Color.BLUE);
		g.drawLine(x, y, x1, y1);
		g.drawLine(x1, y1, x2, y2);
		
		for (int i = 0; i < 10; ++i) {
			rY-=a2;
			drawRects(g, a1, a2, rX, rY, Color.RED, Color.YELLOW);
			rX+=a1;
			
			a2 = rnd.nextInt(y1-y);
		}
	}
	
	void drawRects(Graphics g, int A1, int A2, int X1, int Y1, Color c, Color c1) {
		int a1 = A1;
		int a2 = A2;
		int x = X1;
		int y = Y1;
		g.setColor(c);
		g.fillRect(x, y, a1, a2);
		g.setColor(c1);
		g.drawRect(x, y, a1, a2);
	}

	public BarChart() {
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
		new BarChart();
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
