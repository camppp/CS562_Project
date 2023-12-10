void flushReady(ReplicatedLogImpl *rl, yaraft::Ready *rd) {
  yaraft::pb::HardState *hs = nullptr;
  std::unique_ptr<yaraft::Ready> g(rd);

  // Check if the current node is the leader
  if (rd->currentLeader == rl->Id()) {
    // Process log entries and replicate to followers
    if (!rd->entries.empty()) {
      for (const auto& entry : rd->entries) {
        // Process the log entry, e.g., append to the local log
        rl->appendEntry(entry);
      }
    }

    // Send messages to followers and clear the messages field
    if (!rd->messages.empty()) {
      rl->cluster_->Pass(rd->messages);
      rd->messages.clear();
    }
  }
}
