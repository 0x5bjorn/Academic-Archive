import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Lab06Problem01 extends JFrame {
	Random rnd = new Random();
	ArrayList<Figure> figures = new ArrayList<>();

	CanvasPanel panel = new CanvasPanel();

	Lab06Problem01() {
		panel.setBackground(Color.BLACK);
		panel.setFocusable(true);
		add(panel);

		panel.addKeyListener(new PanelKeyListener());
		panel.addMouseListener(new PanelMouseListener());
	}

	public static void main(String[] args) {
		Lab06Problem01 frame = new Lab06Problem01();
		frame.setTitle("Simplest Graphic Editor");
		frame.setSize(500, 500);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	class CanvasPanel extends JPanel {

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			for (Figure r : figures) {
				r.draw(g);
			}
		}
	}

	class PanelMouseListener extends MouseAdapter {

		@Override
		public void mouseClicked(MouseEvent e) {
			for (Figure r : figures) {
				if (r.contains(e.getX(), e.getY())) {
					JOptionPane.showMessageDialog(null, r.toString());
					break;
				}
			}
		}

	}

	class PanelKeyListener extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {
			switch (e.getKeyCode()) {
			case KeyEvent.VK_1: {
				// JOptionPane.showMessageDialog(null, "key 1 pressed");
				int x = rnd.nextInt(panel.getWidth());
				int y = rnd.nextInt(panel.getHeight());
				int w = rnd.nextInt(100);
				int h = rnd.nextInt(100);
				figures.add(new Rect(x, y, w, h));
				repaint();
				break;
			}
			case KeyEvent.VK_2: {
				int x = rnd.nextInt(panel.getWidth());
				int y = rnd.nextInt(panel.getHeight());
				int r = rnd.nextInt(50);
				figures.add(new Circle(x, y, r));
				repaint();
				break;
			}
			}
		}
	}
}