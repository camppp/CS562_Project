public function getReferenceByKeyword($keyword)
{
    // Sanitize the input keyword to prevent SQL injection
    $keyword = $da->quoteSmart($keyword);

    // Construct the SQL query
    $sql = "SELECT * FROM {$this->table_name} WHERE keyword = '{$keyword}'";

    // Execute the SQL query using the $da object
    $result = $da->query($sql);

    // Process the result to return the reference data as an array
    $referenceData = array();
    while ($row = $result->fetch_assoc()) {
        $referenceData[] = $row;
    }

    return $referenceData;
}