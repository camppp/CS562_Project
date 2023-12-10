void flushReady(ReplicatedLogImpl* rl, Ready* rd) {
  // Check if the current node is the leader
  if (rd->currentLeader == rl->getNodeId()) {
    // Process the log entries and replicate them to the followers
    for (auto& entry : rd->logEntries) {
      // Replicate the log entry to the followers
      rl->replicate(entry);
    }

    // If there are messages to be sent to followers, send them
    if (!rd->messages.empty()) {
      rl->cluster_->pass(rd->messages);
      rd->messages.clear();
    }
  }
}
