import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Lab05Problem05 extends JFrame {
	Robot robot = new Robot(2, 3);
	
	CanvasPanel canvasPanel = new CanvasPanel();

	Lab05Problem05() {
		canvasPanel.setFocusable(true);
		
		add(canvasPanel);
		
		canvasPanel.addKeyListener(new PanelKeyListener());
	}
	
	public static void main(String[] args) {
		Lab05Problem05 frame = new Lab05Problem05();
		
		frame.setTitle("Chessboard");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	
	class PanelKeyListener extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {
			if (e.getKeyCode() == KeyEvent.VK_UP) {
				robot.moveUp();
			} else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
				robot.moveRight();
			} else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
				robot.moveDown();
			} else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
				robot.moveLeft();
			}
			repaint();
		}
		
	}
	
	class CanvasPanel extends JPanel {

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			
			int dw = getWidth() / 8;
			int dh = getHeight() / 8;
			
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					Color c;
					if (i % 2 == 0) {
						c = j % 2 == 0 ? Color.BLACK: Color.WHITE;
					} else {
						c = j % 2 == 0 ? Color.WHITE: Color.BLACK;
					}
					g.setColor(c);
					g.fillRect(dw * j, dh * i, dw, dh);
				}
			}
			
			g.setColor(Color.RED);
			g.fillOval(dw * robot.getCol(), dh * robot.getRow(), dw, dh);
		}
		
	}

}
