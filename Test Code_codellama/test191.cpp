int cli_send::Send(int argc, char* argv[], int target_pid) {
    // Check if the target process is valid
    if (target_pid < 0) {
        return -1;
    }

    // Create a new CLI command
    air::CliCommand* cmd = new air::CliCommand{argc, argv};

    // Send the CLI command to the target process
    int num_cmd = cli_recv->Receive(cmd, target_pid);

    // Check if the command was sent successfully
    if (num_cmd > 0) {
        // Return the number of commands sent
        return num_cmd;
    } else {
        // Return an error code
        return -1;
    }
}
