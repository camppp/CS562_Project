function generateHTMLTable(array $data): string {
    $html = '<table>';

    // Add the table headers
    $html.= '<tr class="thead-dark">';
    foreach ($data as $key => $value) {
        $html.= '<th>'. htmlspecialchars($key). '</th>';
    }
    $html.= '</tr>';

    // Add the table rows
    foreach ($data as $key => $values) {
        foreach ($values as $value) {
            $html.= '<tr>';
            $html.= '<td>'. htmlspecialchars($value). '</td>';
            $html.= '</tr>';
        }
    }

    $html.= '</table>';

    return $html;
}


$data = [
    'رقم التسجيل' => ['1', '2', '3'],
    'إسم الكابتن' => ['Ahmed', 'Sara', 'Mohammed'],
    'الجنسية' => ['Egyptian', 'Lebanese', 'Emirati'],
    'رقم الهاتف' => ['123456', '789012', '345678']
];

echo generateHTMLTable($data);