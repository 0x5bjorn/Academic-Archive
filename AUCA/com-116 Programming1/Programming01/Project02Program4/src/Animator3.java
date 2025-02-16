import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Animator3 extends JFrame {
	String title = "Bouncing Ball";
	Color background = Color.BLACK;
	int delay = 10;
	
	int w;
	int h;
	int x;
	int y;
	int r;
	int dx;
	int dy;
	
	void start() {
		w = getWidth();
		h = getHeight();
		x = 10;
		y = h / 2;
		r = 10;
		dx = 3;
		dy = -5;
	}

	void update() {
		if (y+dy>=h) {
			y = h;
			dy = -dy;
		} else if (y<=h/2-h/4) {
			y = h/4+1;
			dy = -dy;
		} if (x+dx>=w) {
			x = w;
			dx = -dx;
		} if (x+dx<=0) {
			x = 0;
			dx = -dx;
		} else {
			y+=dy;
			dy++;
			x+=dx;
		}
	}

	void draw(Graphics g) {
		g.setColor(Color.RED);
		g.fillOval(x - r, y - r, 2 * r, 2 * r);
	}

	public Animator3() {
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
		new Animator3();
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
