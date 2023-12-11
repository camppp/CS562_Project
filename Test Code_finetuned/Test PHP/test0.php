function validatePlacementForm($formData) {
    // Check if each field is a non-empty string
    foreach ($formData as $field => $value) {
        if (!is_string($value) || empty($value)) {
            return false;
        }
    }
    return true;
}

// Test the function
$formData = array(
    'form_for' => 'Internship',
    'branch' => 'Computer Science',
    'category' => 'General',
   'stu_name' => 'John Doe',
    'father_name' => 'Michael Doe',
   'resi_address' => '123 Main Street',
    'present_address' => '456 Elm Street'
);

var_dump(validatePlacementForm($formData)); // bool(true)