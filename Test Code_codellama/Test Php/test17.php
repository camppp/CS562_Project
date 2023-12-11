function formatKeyValuePairs(array $inputArray, string $delimiter = '|'): string
{
    $output = '';
    foreach ($inputArray as $key => $value) {
        if (is_array($value)) {
            $output .= $key . $delimiter . formatKeyValuePairs($value, $delimiter) . PHP_EOL;
        } else {
            $output .= $key . $delimiter . $value . PHP_EOL;
        }
    }
    return $output;
}