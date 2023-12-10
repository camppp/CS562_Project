void packNextProposal(Round round) {
  auto it = current_proposals_.find(round);
  if (it != current_proposals_.end()) {
    log_->debug("proposal found");
    if (not it->second.empty()) {
      // Add the proposal to the proposal map for the given round
      proposal_map_.emplace(round, emitProposal(round));
      // Log a debug message indicating that data has been fetched for the round
      log_->debug("packNextProposal: data has been fetched for round[{}, {}]",
                  round.block_round,
                  round.reject_round);
      // Add the round to the round queue for further processing
      round_queue_.push(round);
    }
  }
}
