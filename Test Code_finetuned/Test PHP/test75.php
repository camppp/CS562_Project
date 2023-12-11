function processFormData(formData) {
    // Extract form data
    let startDate = formData.get('start date');
    let endDate = formData.get('end date');
    let company = formData.get('company');

    // Validate form data
    if (!startDate ||!endDate ||!company) {
        return { error: 'All fields are required.' };
    }

    // Check if date format is correct
    let startDateObj = new Date(startDate);
    let endDateObj = new Date(endDate);

    if (isNaN(startDateObj.getTime()) || isNaN(endDateObj.getTime())) {
        return { error: 'Invalid date format. Please use YYYY-MM-DD.' };
    }

    // Process form data
    let processedData = {
        startDate: startDate,
        endDate: endDate,
        company: company
    };

    return processedData;
}