function updateTaskCompletion($task_id, $completed_at, $user_id) {
    global $database;

    try {
        $query = "UPDATE tasks SET completed_at = :completed_at, user_id = :user_id WHERE id = :id";
        $statement = $database->prepare($query);
        $statement->bindParam(':id', $task_id, PDO::PARAM_INT);
        $statement->bindParam(':completed_at', $completed_at, PDO::PARAM_STR);
        $statement->bindParam(':user_id', $user_id, PDO::PARAM_INT);
        $statement->execute();
    } catch (PDOException $e) {
        echo "Error: ". $e->getMessage();
    }
}