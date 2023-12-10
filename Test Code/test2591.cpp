#include <unordered_map>
#include <vector>
#include <stdexcept>

class QuestionCache {
private:
    std::unordered_map<int, std::string> answers;

public:
    // Constructor to initialize the cache with a given set of answers
    QuestionCache(const std::vector<std::string>& initialAnswers) {
        for (int i = 0; i < initialAnswers.size(); ++i) {
            answers[i] = initialAnswers[i];
        }
    }

    // Method to retrieve the answer for a given question index
    std::string getAnswer(int questionIndex) {
        if (answers.find(questionIndex) != answers.end()) {
            return answers[questionIndex];
        } else {
            throw std::out_of_range("Question index out of range");
        }
    }

    // Method to update the answer for a given question index
    void updateAnswer(int questionIndex, const std::string& newAnswer) {
        answers[questionIndex] = newAnswer;
    }
};
