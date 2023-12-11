void packNextProposal(Round round) {
  auto it = current_proposals_.find(round);
  if (it != current_proposals_.end()) {
    log_->debug("proposal found");
    if (not it->second.empty()) {
      proposal_map_.emplace(round, emitProposal(round));
      log_->debug("packNextProposal: data has been fetched for round[{}, {}]",
                  round.block_round,
                  round.reject_round);
      round_queue_.push(round);
    }
  } else {
    log_->debug("no proposal found for round[{}, {}]",
                round.block_round,
                round.reject_round);
  }
}
