import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.util.*;

public class Lab06Problem02 extends JFrame {
	Random rnd = new Random();
	ArrayList<Figure> figures = new ArrayList<>();
	CanvasPanel panel = new CanvasPanel();
	Figure selectedFigure = null;

	Lab06Problem02() {
		panel.setBackground(Color.BLACK);
		panel.setFocusable(true);

		add(panel);

		panel.addKeyListener(new PanelKeyListener());
		panel.addMouseListener(new PanelMouseListener());

	}

	public static void main(String[] args) {
		Lab06Problem02 frame = new Lab06Problem02();
		frame.setTitle("Simplest Graphical Editor");
		frame.setSize(500, 500);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	class PanelKeyListener extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {
			if (e.getKeyCode() == KeyEvent.VK_1) {
				int x = rnd.nextInt(panel.getWidth());
				int y = rnd.nextInt(panel.getHeight());
				int w = 25 + rnd.nextInt(50);
				int h = 25 + rnd.nextInt(50);
				figures.add(new Rect(x, y, w, h));
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_2) {
				int x = rnd.nextInt(panel.getWidth());
				int y = rnd.nextInt(panel.getHeight());
				int r = 25 + rnd.nextInt(50);
				figures.add(new Circle(x, y, r));
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_DELETE && selectedFigure != null) {
				figures.remove(selectedFigure);
				selectedFigure = null;
				repaint();
			}

		}

	}

	class PanelMouseListener extends MouseAdapter {

		@Override
		public void mouseClicked(MouseEvent e) {
			for (Figure r : figures) {
				if (r.contains(e.getX(), e.getY())) {
					if (selectedFigure != null) {
						selectedFigure.setSelected(false);
					}
					r.setSelected(true);
					selectedFigure = r;
					repaint();
				}
			}
		}

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

}
