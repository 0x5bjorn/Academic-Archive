import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Clock extends JFrame {
	String title = "Clock";
	Color background = Color.BLACK;
	int delay = 60;

	int w;
	int h;
	int rM;
	int rH;
	int k;
	int x, y, x1, y1, xM, yM, xH, yH;
	double alp, bet, gam;
	
	void start() {
		w = getWidth();
		h = getHeight();
		rM = h / 2;
		rH = rM / 2;
		k = 0;
		alp = (360 / 60 * Math.PI) / 180;
		bet = (360 / 60 * Math.PI) / 180 - 16*Math.PI/30;
		gam = (360 / 60 * Math.PI) / 180;
	}

	void update() {
		bet+=Math.PI/180;
		if (k%360==0){
			gam+=Math.PI/30;
		}
		++k;
	}

	void draw(Graphics g) {
		xM = (int) (w/2 + Math.cos(bet) *h/2);
		yM = (int) (h/2 + Math.sin(bet) *h/2);
		g.setColor(Color.WHITE);
		g.drawLine(w/2, h/2, xM, yM);
		
		xH = (int) (w/2 + Math.cos(gam) * h / 4);
		yH = (int) (h/2 + Math.sin(gam) * h / 4);
		g.setColor(Color.WHITE);
		g.drawLine(w/2, h/2, xH, yH);
		
		for (int i = 0; i < 60; ++i) {
			x = (int) (w/2 + Math.cos(alp*i) * (h / 2 - 20));
			y = (int) (h/2 + Math.sin(alp*i) * (h / 2 - 20));
			x1 = (int) (w/2 + Math.cos(alp*i) * (h / 2));
			y1 = (int) (h/2 + Math.sin(alp*i) * (h / 2));
			g.setColor(Color.WHITE);
			g.drawLine(x, y, x1, y1);
		}
	}

	public Clock() {
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
		new Clock();
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
