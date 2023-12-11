void ProcessWorkerTask(int worker_process_id, content::GlobalFrameRoutingId ancestor_render_frame_host_id) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  if (!sequence_checker_.CalledOnValidSequence()) {
    LOG(ERROR) << "ProcessWorkerTask called on invalid sequence";
    return;
  }

  LOG(INFO) << "Starting task processing for worker process " << worker_process_id
            << " and ancestor render frame host " << ancestor_render_frame_host_id;

  // Perform task processing here
}
