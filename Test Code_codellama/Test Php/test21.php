$fileContent = file_get_contents('input.txt');

$items = [];
preg_match_all('/^(\w+):\s*(\w+)$/m', $fileContent, $matches);
foreach ($matches[1] as $key => $value) {
    $items[$key] = $value;
}