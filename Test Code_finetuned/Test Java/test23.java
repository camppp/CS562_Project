import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class User {
    private String name;
    private String email;
    private int age;

    public User(String name, String email, int age) {
        this.name = name;
        this.email = email;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}

public class CustomerFrame extends JFrame {
    private JTable table;
    private DefaultTableModel tableModel;
    private List<User> users;

    public CustomerFrame() {
        users = new ArrayList<>();

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(0, 2));

        JLabel nameLabel = new JLabel("Name:");
        JTextField nameField = new JTextField();
        panel.add(nameLabel);
        panel.add(nameField);

        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField();
        panel.add(emailLabel);
        panel.add(emailField);

        JLabel ageLabel = new JLabel("Age:");
        JTextField ageField = new JTextField();
        panel.add(ageLabel);
        panel.add(ageField);

        JButton addButton = new JButton("Add User");
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String email = emailField.getText();
                int age = Integer.parseInt(ageField.getText());
                users.add(new User(name, email, age));
                updateTable();
            }
        });
        panel.add(addButton);

        tableModel = new DefaultTableModel(new Object[][]{}, new String[]{"Name", "Email", "Age"});
        table = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(table);

        getContentPane().add(panel, BorderLayout.NORTH);
        getContentPane().add(scrollPane, BorderLayout.CENTER);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setVisible(true);
    }

    private void updateTable() {
        tableModel.setRowCount(0);
        for (User user : users) {
            tableModel.addRow(new Object[]{user.getName(), user.getEmail(), user.getAge()});
        }
    }
}