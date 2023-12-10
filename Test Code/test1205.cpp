// Define a Message enum that represents different types of messages
enum Message {
    RequestShutdown,
    RequestRestart,
    CustomMessage1,
    CustomMessage2,
}

// Implement a function send_message that takes a message as a parameter and prints a corresponding message handling action for each message type
fn send_message(message: Message) {
    match message {
        Message::RequestShutdown => println!("Received request to shut down"),
        Message::RequestRestart => println!("Received request to restart"),
        Message::CustomMessage1 => println!("Received custom message 1"),
        Message::CustomMessage2 => println!("Received custom message 2"),
    }
}

// Test the send_message function by sending different messages
fn main() {
    send_message(Message::RequestShutdown);
    send_message(Message::RequestRestart);
    send_message(Message::CustomMessage1);
    send_message(Message::CustomMessage2);
}
