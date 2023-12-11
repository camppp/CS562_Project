import java.sql.*;

public class TaskDao {
    private Connection connection;

    // Other methods and dependencies

    public int countSprintTasks(long sprintId) {
        int count = 0;
        try {
            String query = "SELECT COUNT(*) FROM tasks WHERE sprint_id =?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setLong(1, sprintId);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                count = resultSet.getInt(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return count;
    }
}