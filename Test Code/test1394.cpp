// Assume the state machine class has methods: start(), stop(), reset(), isTerminated()

cout << "> ";
cout.flush();
getline(input, cmd);

if (!stateMachine.isTerminated()) {
    if (!cmd.empty()) {
        if (cmd == "start") {
            stateMachine.start();
        } else if (cmd == "stop") {
            stateMachine.stop();
        } else if (cmd == "reset") {
            stateMachine.reset();
        } else if (cmd == "exit") {
            // Terminate the program
            exit(0);
        } else {
            // Handle invalid commands
            cout << "Invalid command. Please enter a valid command." << endl;
        }
    }
}
