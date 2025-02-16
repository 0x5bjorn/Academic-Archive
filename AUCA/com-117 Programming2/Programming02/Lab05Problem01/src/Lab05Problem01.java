import java.awt.*;
import javax.swing.*;

public class Lab05Problem01 extends JFrame {
	JPanel mainPanel = new JPanel();
	JPanel controlPanel = new JPanel();
	
	JButton redButton = new JButton("RED");
	JButton greenButton = new JButton("GREEN");
	JButton blueButton = new JButton("BLUE");
	
	Lab05Problem01() {
		setLayout(new BorderLayout());
		
		mainPanel.setBackground(Color.DARK_GRAY);
		add(mainPanel, BorderLayout.CENTER);
		
		controlPanel.setBackground(Color.BLACK);
		controlPanel.add(redButton);
		controlPanel.add(greenButton);
		controlPanel.add(blueButton);
		add(controlPanel, BorderLayout.SOUTH);
	}
	
	public static void main(String[] args) {
		Lab05Problem01 frame = new Lab05Problem01();
		frame.setTitle("First GUI App");
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
	}
}
