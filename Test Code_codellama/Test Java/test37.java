private String getMainWorkoutName() {
    String mainWorkoutName = null;
    while (mainWorkoutName == null) {
        mainWorkoutName = JOptionPane.showInputDialog("Enter the name of the main workout");
        if (mainWorkoutName == null || mainWorkoutName.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter a valid name for the main workout");
        } else if (mainWorkoutNameAlreadyExists(mainWorkoutName)) {
            JOptionPane.showMessageDialog(null, "A main workout with that name already exists. Please enter a different name.");
        }
    }
    return mainWorkoutName;
}

