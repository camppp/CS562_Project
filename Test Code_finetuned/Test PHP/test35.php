function formatKeyValuePairs($inputArray, $delimiter) {
    $formattedString = '';
    foreach ($inputArray as $key => $value) {
        $formattedString.= $key. $delimiter;
        if (is_array($value)) {
            if (array_values($value) === $value) {
                $formattedString.= implode(', ', $value). "\n";
            } else {
                $formattedString.= formatKeyValuePairs($value, ':'). "\n";
            }
        } else {
            $formattedString.= $value. "\n";
        }
    }
    return $formattedString;
}

$inputArray = [ 
    'name' => 'John Doe', 
    'age' => 30, 
    'email' => 'john@example.com', 
    'languages' => ['English', 'French', 'Spanish'], 
    'address' => [ 
       'street' => '123 Main St', 
        'city' => 'Anytown', 
        'country' => 'USA' 
    ] 
];

echo formatKeyValuePairs($inputArray, '|');