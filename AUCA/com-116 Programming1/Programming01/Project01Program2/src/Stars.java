import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Stars extends JFrame {
	String title = "Stars";
	Color background = Color.BLACK;

	Random rand = new Random();

	void draw(Graphics g) {
		int width = getWidth();
		int height = getHeight();
		int a = Math.min(width, height)/8;
		
		for (int j = 0; j < 35; ++j) {
			int c = rand.nextInt(3);

			int x1 = rand.nextInt(width + 1);
			int y1 = rand.nextInt(height + 1); 
			
			for (int i = 0; i < 500; ++i) {
				double alpha = i*Math.PI * rand.nextDouble();
				int rad = rand.nextInt(a);
				int x2 = (int) (x1 + Math.cos(alpha) * rad);
				int y2 = (int) (y1 + Math.sin(alpha) * rad);	
				setColors(g, c);
				g.drawLine(x1, y1, x2, y2);
			}
		}
	}
	void setColors(Graphics g, int a) {
		int a1 = a;
		int i = rand.nextInt(256);
		if (a1==0) {
			g.setColor(new Color(255-i, 0, 0));
		}
		else if (a1==1) {
			g.setColor(new Color(0, 255-i, 0));
		}
		else if (a1==2) {
			g.setColor(new Color(0, 0, 255-i));
		}
	}

	public Stars() {
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
		new Stars();
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
