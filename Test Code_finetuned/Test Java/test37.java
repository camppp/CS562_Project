import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainWorkout {
    private List<String> mainWorkouts;
    private Scanner scanner;

    public MainWorkout() {
        this.mainWorkouts = new ArrayList<>();
        this.scanner = new Scanner(System.in);
    }

    private void addNewMainWorkoutOnClick() {
        String mainWorkoutName = getMainWorkoutName();
        if (mainWorkoutName!= null) {
            mainWorkouts.add(mainWorkoutName);
            System.out.println("New main workout added: " + mainWorkoutName);
        } else {
            System.out.println("Failed to add new main workout. Please try again.");
        }
    }

    private String getMainWorkoutName() {
        System.out.println("Enter the name of the new main workout:");
        String name = scanner.nextLine();
        if (name.isEmpty()) {
            System.out.println("The name of the main workout cannot be empty. Please try again.");
            return null;
        }
        if (mainWorkouts.contains(name)) {
            System.out.println("A main workout with the name " + name + " already exists. Please try again.");
            return null;
        }
        return name;
    }
}