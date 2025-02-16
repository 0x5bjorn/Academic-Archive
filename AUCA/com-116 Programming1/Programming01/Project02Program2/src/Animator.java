import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Animator extends JFrame {
	String title = "Bouncing Ball";
	Color background = Color.BLACK;
	int delay = 10;
	
	Color ballColor1 = Color.BLUE;
	int ballX1, ballY1;
	int ballDx1 = 2, ballDy1 = ballDx1*2;
	int ballRadius1 = 10;
	int ballDiameter1 = ballRadius1*2;
	
	Color ballColor2 = Color.GREEN;
	int ballX2, ballY2;
	int ballDx2 = 2, ballDy2 = ballDx2*2;
	int ballRadius2 = 10;
	int ballDiameter2 = ballRadius2*2;
	
	Color ballColor3 = Color.RED;
	int ballX3, ballY3;
	int ballDx3 = 2, ballDy3 = ballDx3*2;
	int ballRadius3 = 10;
	int ballDiameter3 = ballRadius3*2;
	
	void start() {
		ballX1 = getWidth() / 2 - ballDiameter1;
		ballY1 = getHeight() / 2 - ballDiameter1*2;
		
		ballX2 = getWidth() / 2;
		ballY2 = getHeight() / 2;
		
		ballX3 = getWidth() / 2 + ballDiameter3;
		ballY3 = getHeight() / 2 + ballDiameter3*2;
	}

	void update() {
        ballX1 += ballDx1;
        ballY1 += ballDy1;
        
        if (ballY1 - ballRadius1 < 0 || ballY1 + ballRadius1 > getHeight()) {
        	ballDy1 *= -1;
        }
        if (ballX1 - ballRadius1 < 0 || ballX1 + ballRadius1 > getWidth()) {
        	ballDx1 *= -1;
        }
        
        ballX2 += ballDx2;
        ballY2 += ballDy2;
        
        if (ballY2 - ballRadius2 < 0 || ballY2 + ballRadius2 > getHeight()) {
        	ballDy2 *= -1;
        }
        if (ballX2 - ballRadius2 < 0 || ballX2 + ballRadius2 > getWidth()) {
        	ballDx2 *= -1;
        }
        
        ballX3 += ballDx3;
        ballY3 += ballDy3;
        
        if (ballY3 - ballRadius3 < 0 || ballY3 + ballRadius3 > getHeight()) {
        	ballDy3 *= -1;
        }
        if (ballX3 - ballRadius3 < 0 || ballX3 + ballRadius3 > getWidth()) {
        	ballDx3 *= -1;
        }
	}

	void draw(Graphics g) {
        g.setColor(ballColor1);
        int x1 = ballX1 - ballRadius1;
        int y1 = ballY1 - ballRadius1;
        g.fillOval(x1, y1, ballDiameter1, ballDiameter1);
        
        g.setColor(ballColor2);
        int x2 = ballX2 - ballRadius2;
        int y2 = ballY2 - ballRadius2;
        g.fillOval(x2, y2, ballDiameter2, ballDiameter2);
        
        g.setColor(ballColor3);
        int x3 = ballX3 - ballRadius3;
        int y3 = ballY3 - ballRadius3;
        g.fillOval(x3, y3, ballDiameter3, ballDiameter3);
	}

	public Animator() {
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
		new Animator();
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
