import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Lab05Problem02 extends JFrame {
	JPanel mainPanel = new JPanel();
	JPanel controlPanel = new JPanel();
	
	JButton redButton = new JButton("RED");
	JButton greenButton = new JButton("GREEN");
	JButton blueButton = new JButton("BLUE");
	
	Lab05Problem02() {
		setLayout(new BorderLayout());
		
		mainPanel.setBackground(Color.RED);
		add(mainPanel, BorderLayout.CENTER);
		
		controlPanel.setBackground(Color.DARK_GRAY);
		controlPanel.add(redButton);
		controlPanel.add(greenButton);
		controlPanel.add(blueButton);
		
		add(controlPanel, BorderLayout.SOUTH);
		
		
		redButton.addActionListener(new ButtonListener(Color.RED));
		greenButton.addActionListener(new ButtonListener(Color.GREEN));
		blueButton.addActionListener(new ButtonListener(Color.BLUE));
		
	}
	
	public static void main(String[] args) {
		Lab05Problem02 frame = new Lab05Problem02();
			
		frame.setTitle("First GUI App");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

	// inner class
	class ButtonListener implements ActionListener {
		Color color;
		
		ButtonListener(Color aColor) {
			color = aColor;
		}
		
		@Override
		public void actionPerformed(ActionEvent e) {
			mainPanel.setBackground(color);
			
		}
		
	}
	
}


