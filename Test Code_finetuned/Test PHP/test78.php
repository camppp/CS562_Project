function validateEventForm() {
    var date = document.getElementById('date').value;
    var startTime = document.getElementById('startTime').value;
    var endTime = document.getElementById('endTime').value;

    var dateRegex = /^\d{4}-\d{2}-\d{2}$/;
    var timeRegex = /^(0[1-9]|1[0-2]):[0-5][0-9]$/;

    if (!date ||!dateRegex.test(date)) {
        alert('Invalid date format. Please enter the date in YYYY-MM-DD format.');
        return false;
    }

    if (!startTime ||!timeRegex.test(startTime)) {
        alert('Invalid start time format. Please enter the time in HH:MM format.');
        return false;
    }

    if (!endTime ||!timeRegex.test(endTime)) {
        alert('Invalid end time format. Please enter the time in HH:MM format.');
        return false;
    }

    var start = new Date('1/1/2000'+ startTime);
    var end = new Date('1/1/2000'+ endTime);

    if (end < start) {
        alert('End time must be later than start time.');
        return false;
    }

    document.getElementById('eventForm').submit();
    return true;
}