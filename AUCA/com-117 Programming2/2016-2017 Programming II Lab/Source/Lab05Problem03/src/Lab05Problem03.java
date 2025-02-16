import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Lab05Problem03 extends JFrame {
	JPanel panel = new JPanel();
	
	
	Lab05Problem03() {
		panel.setBackground(Color.DARK_GRAY);
		add(panel);
		
		panel.addMouseMotionListener(new ButtonMouseMotionListener());
	}
	public static void main(String[] args) {
		Lab05Problem03 frame = new Lab05Problem03();
		
		frame.setTitle("Move mouse");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

//	class ButtonMouseMotionListener implements MouseMotionListener {
//
//		@Override
//		public void mouseDragged(MouseEvent arg0) {
//			// TODO Auto-generated method stub
//			
//		}
//
//		@Override
//		public void mouseMoved(MouseEvent e) {
//			setTitle(e.getX() + ", " + e.getY());
//		}
//		
//	}
	
	class ButtonMouseMotionListener extends MouseMotionAdapter {

		@Override
		public void mouseMoved(MouseEvent e) {
			setTitle(e.getX() + ", " + e.getY());
		}
		
	}
}
