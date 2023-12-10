void simulate_gprs_getIPAddress(FeedbackInterface& feedback) {
    // Check if the blocked flag is already set to true
    if (feedback.blocked) {
        return;
    }

    // Check if the time elapsed since the timer started is greater than 60000 milliseconds
    if (feedback.timer.elapsed() > 60000) {
        feedback.blocked = false;
    }

    // Set the blocked flag to the logical NOT of the result of calling the ResponseListener function with the Reply::OK_ string and the FeedbackInterface object
    feedback.blocked = !feedback.ResponseListener("Reply::OK_", feedback);
}
