public function saveState($data) {
    $stateData = serialize($data);
    $createdAt = date('Y-m-d H:i:s');

    $query = "INSERT INTO states (state_data, created_at) VALUES (:stateData, :createdAt)";
    $stmt = $this->db->prepare($query);
    $stmt->bindParam(':stateData', $stateData);
    $stmt->bindParam(':createdAt', $createdAt);

    if ($stmt->execute()) {
        return $this->db->lastInsertId();
    } else {
        return false;
    }
}