function validateForm() {
    var form = document.forms[0]; // Assuming there is only one form in the page
    var saveButton = form.querySelector('input[type="submit"]');
    var isFormValid = true;

    // Loop through all form fields
    for (var i = 0; i < form.elements.length; i++) {
        var field = form.elements[i];

        // Check if the field is not empty
        if (field.type!=='submit' && field.type!== 'button' && field.value.trim() === '') {
            isFormValid = false;
            break;
        }
    }

    // Update the state of the "Simpan" button
    saveButton.disabled =!isFormValid;
}