function generateHTMLTable(array $data): string
{
    $html = '<table>';
    $html .= '<tr class="thead-dark">';
    foreach ($data as $key => $value) {
        $html .= '<th>' . $key . '</th>';
    }
    $html .= '</tr>';
    foreach ($data as $row) {
        $html .= '<tr>';
        foreach ($row as $cell) {
            $html .= '<td>' . $cell . '</td>';
        }
        $html .= '</tr>';
    }
    $html .= '</table>';
    return $html;
}