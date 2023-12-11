function generateCSV($tableHeader, $data) {
    // Convert table headers and data to GBK
    $tableHeader = mb_convert_encoding($tableHeader, 'GBK', 'UTF-8');
    $data = array_map(function($row) {
        return mb_convert_encoding($row, 'GBK', 'UTF-8');
    }, $data);

    // Open output stream
    $output = fopen('php://output', 'w');

    // Write table headers
    fputcsv($output, $tableHeader);

    // Write data rows
    foreach ($data as $row) {
        fputcsv($output, $row);
    }

    // Close the output stream
    fclose($output);
}