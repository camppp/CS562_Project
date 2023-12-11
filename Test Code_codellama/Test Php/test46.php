function generateCSV($tableHeader, $data) {
  // Convert the headers and data to GBK encoding
  $headers = array_map(function($header) {
    return mb_convert_encoding($header, 'GBK', 'UTF-8');
  }, $tableHeader);
  $data = array_map(function($row) {
    return array_map(function($cell) {
      return mb_convert_encoding($cell, 'GBK', 'UTF-8');
    }, $row);
  }, $data);

  // Generate the CSV file
  $csv = implode("\n", array_map(function($row) {
    return implode(',', $row);
  }, $data));

  // Add the headers to the CSV file
  $csv = implode("\n", array_merge($headers, [$csv]));

  // Return the CSV file
  return $csv;
}