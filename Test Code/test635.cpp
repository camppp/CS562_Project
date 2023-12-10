#include <iostream>
#include <string>

// Define the states for the questionnaire module
enum State {
    START,
    QUESTION_1,
    QUESTION_2,
    QUESTION_3,
    QUESTION_4,
    END
};

// Allowable responses
std::string allowableResponses = "1234";

// Questionnaire name
std::string questionnaireName = "BIS BAS";

// Current state
State currentState = START;

// Function to handle user responses and transition between states
void handleUserResponse(char response) {
    if (currentState == START) {
        if (allowableResponses.find(response) != std::string::npos) {
            currentState = QUESTION_1;
            std::cout << "Question 1: How often do you feel worried about making mistakes? (1-4)" << std::endl;
        } else {
            std::cout << "Invalid response. Please enter a valid response (1-4)." << std::endl;
        }
    } else if (currentState == QUESTION_1) {
        if (allowableResponses.find(response) != std::string::npos) {
            currentState = QUESTION_2;
            std::cout << "Question 2: How often do you feel like you need a lot of excitement in your life? (1-4)" << std::endl;
        } else {
            std::cout << "Invalid response. Please enter a valid response (1-4)." << std::endl;
        }
    } else if (currentState == QUESTION_2) {
        if (allowableResponses.find(response) != std::string::npos) {
            currentState = QUESTION_3;
            std::cout << "Question 3: How often do you feel worried about the possibility of something unpleasant happening? (1-4)" << std::endl;
        } else {
            std::cout << "Invalid response. Please enter a valid response (1-4)." << std::endl;
        }
    } else if (currentState == QUESTION_3) {
        if (allowableResponses.find(response) != std::string::npos) {
            currentState = QUESTION_4;
            std::cout << "Question 4: How often do you feel happy? (1-4)" << std::endl;
        } else {
            std::cout << "Invalid response. Please enter a valid response (1-4)." << std::endl;
        }
    } else if (currentState == QUESTION_4) {
        if (allowableResponses.find(response) != std::string::npos) {
            currentState = END;
            std::cout << "Questionnaire completed. Thank you for your responses." << std::endl;
        } else {
            std::cout << "Invalid response. Please enter a valid response (1-4)." << std::endl;
        }
    }
}

int main() {
    std::cout << "Welcome to the " << questionnaireName << " questionnaire." << std::endl;
    std::cout << "Please respond to the following questions using the numbers 1-4." << std::endl;

    // Simulate user responses for the purpose of demonstration
    handleUserResponse('1');
    handleUserResponse('2');
    handleUserResponse('3');
    handleUserResponse('4');

    return 0;
}
