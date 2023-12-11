function generateMessageTable($messages) {
  $table = '<table border="1">';
  $table .= '<tr>';
  $table .= '<th>Name</th>';
  $table .= '<th>Phone Number</th>';
  $table .= '<th>Email</th>';
  $table .= '</tr>';
  foreach ($messages as $message) {
    $table .= '<tr>';
    $table .= '<td>' . $message['name'] . '</td>';
    $table .= '<td>' . $message['no_telepon'] . '</td>';
    $table .= '<td>' . $message['email'] . '</td>';
    $table .= '</tr>';
  }
  $table .= '</table>';
  return $table;
}