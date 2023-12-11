function generateMessageTable($messages) {
    $html = '<table>';
    $html.= '<tr><th>Name</th><th>Phone Number</th><th>Email</th></tr>';
    foreach ($messages as $message) {
        $html.= '<tr>';
        $html.= '<td>'. $message['name']. '</td>';
        $html.= '<td>'. $message['no_telepon']. '</td>';
        $html.= '<td>'. $message['email']. '</td>';
        $html.= '</tr>';
    }
    $html.= '</table>';
    return $html;
}

$messages = [
    ['name' => 'John Doe', 'no_telepon' => '123-456-7890', 'email' => 'john@example.com'],
    ['name' => 'Jane Smith', 'no_telepon' => '987-654-3210', 'email' => 'jane@example.com'],
    // Additional messages can be added here
];

echo generateMessageTable($messages);