import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Lab05Problem04 extends JFrame {
	CanvasPanel canvasPanel = new CanvasPanel();

	Lab05Problem04() {
		add(canvasPanel);
	}

	public static void main(String[] args) {
		Lab05Problem04 frame = new Lab05Problem04();
		frame.setTitle("First GUI App");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

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
						c = j % 2 == 0 ? Color.BLACK : Color.WHITE;
					} else {
						c = j % 2 == 0 ? Color.WHITE : Color.BLACK;
					}
					g.setColor(c);
					g.fillRect(dw * j, dh * i, dw, dh);
				}
			}
		}
	}
}
