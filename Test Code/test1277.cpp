java
public class GridGame {
    private boolean[][] box;
    private boolean[][] goal;

    public void resize(int rows, int cols) {
        box = new boolean[rows][cols];
        goal = new boolean[rows][cols];
    }

    public void setBoxCell(int row, int col, boolean value) {
        if (row >= 0 && row < box.length && col >= 0 && col < box[0].length) {
            box[row][col] = value;
        } else {
            // Handle invalid cell coordinates
            System.out.println("Invalid cell coordinates for box grid");
        }
    }

    public boolean checkBoxCell(int row, int col) {
        if (row >= 0 && row < box.length && col >= 0 && col < box[0].length) {
            return box[row][col];
        } else {
            // Handle invalid cell coordinates
            System.out.println("Invalid cell coordinates for box grid");
            return false;
        }
    }

    public void setGoalCell(int row, int col, boolean value) {
        if (row >= 0 && row < goal.length && col >= 0 && col < goal[0].length) {
            goal[row][col] = value;
        } else {
            // Handle invalid cell coordinates
            System.out.println("Invalid cell coordinates for goal grid");
        }
    }

    public boolean checkGoalCell(int row, int col) {
        if (row >= 0 && row < goal.length && col >= 0 && col < goal[0].length) {
            return goal[row][col];
        } else {
            // Handle invalid cell coordinates
            System.out.println("Invalid cell coordinates for goal grid");
            return false;
        }
    }
}
