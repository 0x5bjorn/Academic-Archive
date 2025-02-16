import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Circles extends JFrame {
	String title = "Lab 05 Problem 04";
	Color background = Color.BLACK;

	void draw(Graphics g) {
		final int NUMBERofCIRCLES = 20;
		int width = getWidth();
		int height = getHeight();
		int centerX = width/2;
		int centerY = height/2;
		
		int initialRadius = Math.min(width, height) / 2;
		int colorStep = 255/NUMBERofCIRCLES;
		int radiusStep = initialRadius/NUMBERofCIRCLES;
		
		for (int i = 0, red = 0, radius = initialRadius; 
			 i < NUMBERofCIRCLES; 
			 ++i, red+=colorStep, radius -= radiusStep) {
			Color color = new Color(red, 0, 0);
			g.setColor(color);
			
			int diameter = 2 * radius;

			int x = centerX - radius;
			int y = centerY - radius;

			g.fillOval(x, y, diameter, diameter);
		}
	}

	public Circles() {
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
		new Circles();
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
