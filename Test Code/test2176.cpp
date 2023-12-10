void YourClass::launch_button_toggled(bool checked) {
    if (checked) {
        qDebug() << "Launching process...";
        // Add code to start the process when the button is checked
    } else {
        qDebug() << "Process aborted.";
        // Add code to handle the process being aborted when the button is unchecked
    }
}
