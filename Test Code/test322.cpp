int scoreOrganization(const vector<Session>& sessions) {
    int score = 0;
    // Calculate the distribution of topics
    unordered_map<string, int> topicCount;
    for (const auto& session : sessions) {
        for (const auto& talk : session.talks) {
            topicCount[talk.topic]++;
        }
    }
    // Calculate the relevance of talks within a session
    for (const auto& session : sessions) {
        for (const auto& talk : session.talks) {
            score += talk.relevance * talk.importance;
        }
    }
    // Calculate the overall coherence of the schedule
    for (const auto& session : sessions) {
        for (const auto& talk : session.talks) {
            score += talk.coherence * talk.importance;
        }
    }
    return score;
}
