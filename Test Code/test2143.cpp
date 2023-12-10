// Assuming the necessary includes and class definition

// In the constructor or initialization function
ui->btn_deleteMeth->setDisabled(true);
connect(ui->btnbx, &QDialogButtonBox::accepted, this, &YourClassName::handleAccept);
