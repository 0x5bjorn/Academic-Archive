import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Star extends JFrame {
	String title = "Star";
	Color background = Color.BLACK;

	Random rand = new Random();

	void draw(Graphics g) {
		int width = getWidth();
		int height = getHeight();
		int a = Math.min(width, height)/2;
		
		for (int i = 0; i < 500; ++i) {
			int red = rand.nextInt(256);
			g.setColor(new Color(red, 0, 0));
			
			double alpha = 2*Math.PI *rand.nextDouble();
			int x1 = width / 2;
			int y1 = height / 2;
			int rad = rand.nextInt(a);
			int x2 = (int) (x1 + Math.cos(alpha) * rad);
			int y2 = (int) (y1 + Math.sin(alpha) * rad);	
			g.drawLine(x1, y1, x2, y2);
		}
	}

	public Star() {
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
		new Star();
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
