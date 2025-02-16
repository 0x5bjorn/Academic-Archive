import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

import java.sql.*;
import java.util.*;

public class Project1 extends JFrame {
	public final static String url = "jdbc:mysql://localhost:3306/sultan";
	public final static String user = "sultan";
	public final static String pswd = "mysql";
	
	private static Connection con;
	private static Statement stmt;
	private static ResultSet rs;
	
	static String statusInfo = "";
	static String placeInfo = "";
	static String dateInfo = "";
	static String timeInfo = "";
	static String descInfo = "";
	static String pPhoneInfo = "";
	static String pEmailInfo = "";

	static String categoryInfo = "";
	static String subCategoryInfo = "";
	static String brandInfo = "";
	static String colorInfo = "";

	static String cName = "";
	static String scName = "";
	static String bName = "";
	static String coName = "";

	private static String result = "";
	static ArrayList<String> categoryList = new ArrayList<String>();
	static ArrayList<String> subCategoryList = new ArrayList<String>();
	static ArrayList<String> brandList = new ArrayList<String>();
	static ArrayList<String> colorList = new ArrayList<String>();
	
	static JTextArea description = new JTextArea(11, 30);
	static JTextField date = new JTextField();
	static JTextField time = new JTextField();
	static JTextField place = new JTextField();
	static JTextArea results = new JTextArea();
	static JTextField phone = new JTextField();
	static JTextField email = new JTextField();
	static JScrollPane sp;
	
	static JPanel mainPanel = new JPanel();
	static JPanel searchPanelTop = new JPanel();
	static JPanel searchPanelBtm = new JPanel();
	static JPanel resultPanelTop = new JPanel();
	static JPanel resultPanelBtm = new JPanel();
	static JPanel personalInfoPanel = new JPanel();
	static JPanel personalInfoPanelBtm = new JPanel();
	
	static JButton next = new JButton("NEXT");
	static JButton notInList = new JButton("NOT IN LIST");
	static JButton done = new JButton("DONE");
	static JButton add = new JButton("ADD");
	static JButton back = new JButton("BACK");

	static JComboBox status = new JComboBox();
	static JComboBox categories = new JComboBox();
	static JComboBox subCategories = new JComboBox();
	static JComboBox brands = new JComboBox();
	static JComboBox colors = new JComboBox();

	static ButtonListener bl = new ButtonListener();
	
	Project1() {
		searchPanelTop.setLayout(new GridLayout(8, 2));
		searchPanelTop.setBackground(Color.CYAN);	
		searchPanelTop.add(new JLabel("STATUS:"));
		status.addItem("LOST");
		status.addItem("FOUND");
		searchPanelTop.add(status);	
		searchPanelTop.add(new JLabel("DATE:*"));
		searchPanelTop.add(date);
		searchPanelTop.add(new JLabel("TIME:*"));
		searchPanelTop.add(time);
		searchPanelTop.add(new JLabel("PLACE:*"));
		searchPanelTop.add(place);
		
		searchPanelTop.add(new JLabel("CATEGORY:"));
		searchPanelTop.add(categories);
		
		searchPanelTop.add(new JLabel("SUBCATEGORY:"));
		searchPanelTop.add(subCategories);
			
		searchPanelTop.add(new JLabel("BRAND:*"));
		searchPanelTop.add(brands);
		
		searchPanelTop.add(new JLabel("COLOR:*"));
		searchPanelTop.add(colors);

		searchPanelBtm.setLayout(new FlowLayout());
		searchPanelBtm.setBackground(Color.CYAN);
		searchPanelBtm.add(new JLabel("Additional description:*"));
		description.setLineWrap(true);
		description.setWrapStyleWord(true);
		searchPanelBtm.add(description);
		searchPanelBtm.add(next);

		mainPanel.setLayout(new GridLayout(2, 1));
		mainPanel.add(searchPanelTop);
		mainPanel.add(searchPanelBtm);

		resultPanelTop.setLayout(new BorderLayout());	
		resultPanelBtm.add(notInList);


		personalInfoPanel.setLayout(new FlowLayout());
		personalInfoPanel.add(new JLabel("Your phone:"));
		phone.setPreferredSize(new Dimension(200, 25));
		personalInfoPanel.add(phone);
		personalInfoPanel.add(new JLabel("Your email:"));
		email.setPreferredSize(new Dimension(200, 25));
		personalInfoPanel.add(email);
		personalInfoPanel.add(new JLabel("Leave your phone and/or email info to contact you"));
		personalInfoPanelBtm.setLayout(new FlowLayout());
		personalInfoPanelBtm.add(add);
		
		next.addActionListener(bl);
		notInList.addActionListener(bl);
		done.addActionListener(bl);
		add.addActionListener(bl);
		back.addActionListener(bl);
		setLayout(new BorderLayout());
		add(mainPanel);
	}

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		Project1 frame = new Project1();
		frame.setTitle("Lost&Found");
		frame.setSize(800, 400);	
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
		try {
			//Class.forName("com.mysql.cj.jdbc.Driver");
			
			con = DriverManager.getConnection(url, user, pswd);
			stmt = con.createStatement();
			
			//    ___fill categories___	
			String categoryQ = "select category_name from Categories;";
			rs = stmt.executeQuery(categoryQ);	
			while (rs.next()) {
				cName = rs.getString("category_name");
				categoryList.add(cName);
			}
			categories.setModel(new DefaultComboBoxModel(categoryList.toArray()));
			categories.addActionListener(bl);

			//    ___fill brands___		
			String brandQ = "select brand_name from Brands;";
			rs = stmt.executeQuery(brandQ);	
			while (rs.next()) {
				bName = rs.getString("brand_name");
				brandList.add(bName);
			}
			brands.setModel(new DefaultComboBoxModel(brandList.toArray()));
			
			//    ___fill colors___
			String colorQ = "select color_name from Colors;";
			rs = stmt.executeQuery(colorQ);	
			while (rs.next()) {
				coName = rs.getString("color_name");
				colorList.add(coName);
			}
			colors.setModel(new DefaultComboBoxModel(colorList.toArray()));
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} 
	}

	private static class ButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if (e.getSource() == next) {
				statusInfo = String.valueOf(status.getSelectedItem());
				placeInfo = String.valueOf(place.getText());
				dateInfo = String.valueOf(date.getText());
				timeInfo = String.valueOf(time.getText());
				descInfo = String.valueOf(description.getText());

				categoryInfo = String.valueOf(categories.getSelectedItem());
				subCategoryInfo = String.valueOf(subCategories.getSelectedItem());
				brandInfo = String.valueOf(brands.getSelectedItem());
				colorInfo = String.valueOf(colors.getSelectedItem());

				mainPanel.removeAll();
				mainPanel.repaint();
				mainPanel.revalidate();
				
				mainPanel.setLayout(new BorderLayout());
				mainPanel.add(resultPanelTop);
				results.setEditable(true);	
				
				// select query for finding items according to the filters
				try {
					String resultQ = "select ii.status, ii.description, ii.personPhone, ii.personEmail from ItemInfo ii join ItemCharacteristics ic on ii.item_id = ic.item_id where ic.item_id in (select ic.item_id from ItemCharacteristics ic join (ColorCharacteristic cc join Colors co on cc.color_id = co.color_id) on ic.item_id = cc.item_id where co.color_name = '" + colorInfo + "') and ic.mainCharacteristics_id in (select mainCharacteristics_id from MainCharacteristics mc join Brands b on mc.brand_id = b.brand_id join (TypeCharacteristic tc join Categories c on tc.category_id = c.category_id join SubCategories sc on tc.subCategory_id = sc.subCategory_id) on mc.typeCharacteristic_id = tc.typeCharacteristic_id where c.category_name = '" + categoryInfo + "' and sc.subCategory_name = '" + subCategoryInfo + "' and b.brand_name = '" + brandInfo + "') and ii.status = if('" + statusInfo + "' = 'LOST', 'FOUND', 'LOST');";
					rs = stmt.executeQuery(resultQ);
					while (rs.next()) {
						result = result + "Status: " + rs.getString(1) + ", Description: '" + rs.getString(2) + "', Phone: " + rs.getString(3) + ", Email: " + rs.getString(4) + "\n";						
					}
				} catch (SQLException sqle) {
					System.out.println(sqle.getMessage());
				}
				
				results.setText(result);
				results.setEditable(false);
				sp = new JScrollPane(results, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
				resultPanelTop.add(results, BorderLayout.CENTER); 
				resultPanelBtm.add(done);
				resultPanelBtm.add(back);
				mainPanel.add(resultPanelBtm, BorderLayout.SOUTH);
				resultPanelBtm.setLayout(new FlowLayout());

				mainPanel.repaint();
				mainPanel.revalidate();
			} else if (e.getSource() == notInList) {
				mainPanel.removeAll();
				mainPanel.repaint();
				mainPanel.revalidate();
				
				personalInfoPanelBtm.add(done);
				personalInfoPanelBtm.add(back);
				mainPanel.setLayout(new BorderLayout());
				mainPanel.add(personalInfoPanel);
				mainPanel.add(personalInfoPanelBtm, BorderLayout.SOUTH);
				
				mainPanel.repaint();
				mainPanel.revalidate();
			} else if (e.getSource() == done) {
				System.exit(0);
			} else if (e.getSource() == back) {
				result = "";
				
				mainPanel.removeAll();
				mainPanel.repaint();
				mainPanel.revalidate();
	
				mainPanel.setLayout(new GridLayout(2, 1));
				mainPanel.add(searchPanelTop);
				mainPanel.add(searchPanelBtm);

				mainPanel.repaint();
				mainPanel.revalidate();
			} else if (e.getSource() == add) {
				pPhoneInfo = String.valueOf(phone.getText());
				pEmailInfo = String.valueOf(email.getText());
				
				// multiple insert queries for adding item to db if there is no such one
				String insertQ = "";
				try {
					insertQ = "insert into ItemInfo (status, description, personPhone, personEmail) values('" + statusInfo + "', '" + descInfo + "', '" + pPhoneInfo + "', '" + pEmailInfo + "');";
					stmt.addBatch(insertQ);
				
					insertQ = "insert into MainCharacteristics (typeCharacteristic_id, brand_id) values((select tc.typeCharacteristic_id from TypeCharacteristic tc join Categories c on tc.category_id = c.category_id  join SubCategories sc on tc.subCategory_id = sc.subCategory_id where c.category_name = '" + categoryInfo + "' and sc.subCategory_name = '" + subCategoryInfo + "'), (select brand_id from Brands where brand_name = '" + brandInfo + "'));";
					stmt.addBatch(insertQ);
	
					insertQ = "insert into ItemCharacteristics (item_id, mainCharacteristics_id) values ((select max(item_id) from ItemInfo), (select mainCharacteristics_id from MainCharacteristics mc join Brands b on mc.brand_id = b.brand_id join (TypeCharacteristic tc join Categories c on tc.category_id = c.category_id join SubCategories sc on tc.subCategory_id = sc.subCategory_id) on mc.typeCharacteristic_id = tc.typeCharacteristic_id where c.category_name = '" + categoryInfo + "' and sc.subCategory_name = '" + subCategoryInfo + "' and b.brand_name = '" + brandInfo + "'));";
					stmt.addBatch(insertQ);
					
					insertQ = "insert into ColorCharacteristic (item_id, color_id) values ((select max(item_id) from ItemInfo), (select color_id from Colors where color_name = '" + colorInfo + "'));";
					stmt.addBatch(insertQ);

					stmt.executeBatch();
					con.commit();
				} catch (SQLException sqle) {
					System.out.println(sqle.getMessage());
				}

			} else if (e.getSource() == categories) {
				try {
					subCategoryList.clear();
					cName = String.valueOf(categories.getSelectedItem());
					// select query for showing subcategories of chosen category in list for filtering
					String subCategoryQ = "select sc.subCategory_name from TypeCharacteristic tc join Categories c on tc.category_id = c.category_id join SubCategories sc on tc.subCategory_id = sc.subCategory_id where c.category_name = '" + cName + "'";
					rs = stmt.executeQuery(subCategoryQ);
					while (rs.next()) {
						scName = rs.getString("subCategory_name");
						subCategoryList.add(scName);
					}
					subCategories.setModel(new DefaultComboBoxModel(subCategoryList.toArray()));
				} catch (SQLException sqle) {
						System.out.println(sqle.getMessage());
				}
			}
		}
	}
}
