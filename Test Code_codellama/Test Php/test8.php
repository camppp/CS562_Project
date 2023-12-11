function updateTaskCompletion($task_id, $completed_at, $user_id) {
    // Prepare the SQL statement
    $sql = "UPDATE tasks SET completed_at = :completed_at WHERE id = :task_id AND user_id = :user_id";

    // Prepare the statement
    $stmt = $database->prepare($sql);

    // Bind the parameters
    $stmt->bindParam(':completed_at', $completed_at, PDO::PARAM_STR);
    $stmt->bindParam(':task_id', $task_id, PDO::PARAM_INT);
    $stmt->bindParam(':user_id', $user_id, PDO::PARAM_INT);

    // Execute the statement
    $stmt->execute();

    // Return the number of rows affected
    return $stmt->rowCount();
}