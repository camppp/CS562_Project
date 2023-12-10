rust
// Define the Message enum to represent different types of messages
enum Message {
    RequestShutdown,
    CustomMessage1,
    CustomMessage2,
}

// Implement the send_message function to handle different message types
fn send_message(msg: Message) {
    match msg {
        Message::RequestShutdown => println!("Received RequestShutdown: Initiating shutdown process"),
        Message::CustomMessage1 => println!("Received CustomMessage1: Performing custom action 1"),
        Message::CustomMessage2 => println!("Received CustomMessage2: Performing custom action 2"),
    }
}

fn main() {
    // Sending a RequestShutdown message
    send_message(Message::RequestShutdown);

    // Sending a CustomMessage1
    send_message(Message::CustomMessage1);

    // Sending a CustomMessage2
    send_message(Message::CustomMessage2);
}
