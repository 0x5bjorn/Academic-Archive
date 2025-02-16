import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Snow extends JFrame {
	String title = "Animation Template";
	Color background = Color.BLACK;
	int delay = 80;
	
	final int N = 100;
	final int R_MAX = 20;
	
	int[] x = new int[N]; 
	int[] y = new int[N]; 
	int[] r = new int[N];
	Color[] c = new Color[N];
	Random rnd = new Random();
	
	void start() {
		for (int i=0; i<N; ++i) {
			r[i] = rnd.nextInt(R_MAX) + 1;
			x[i] = rnd.nextInt(getWidth());
        	y[i] = rnd.nextInt(getHeight());
        	c[i] = new Color(rnd.nextInt(256),
        					 rnd.nextInt(256),
        					 rnd.nextInt(256));
		}
	}

	void update() {
		for (int i=0; i<N; ++i) {
			x[i] = x[i] - r[i] + rnd.nextInt(2*r[i]);
        	y[i] += r[i];
        	if (y[i] > getHeight()) {
        		x[i] = rnd.nextInt(getWidth());
        		y[i]=-r[i];
        	}
		}
	}

	void draw(Graphics g) {
		for (int i=0; i<N; ++i) {
			g.setColor(Color.WHITE);
        	g.drawLine(x[i], y[i]-r[i], x[i], y[i]+r[i]);
        	g.drawLine(x[i]-r[i], y[i], x[i]+r[i], y[i]);
        	g.drawLine(x[i]+r[i]/2, y[i]-r[i]/2, x[i]-r[i]/2, y[i]+r[i]/2);
        	g.drawLine(x[i]+r[i]/2, y[i]+r[i]/2, x[i]-r[i]/2, y[i]-r[i]/2);
		}
	}

	public Snow() {
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
		new Snow();
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
