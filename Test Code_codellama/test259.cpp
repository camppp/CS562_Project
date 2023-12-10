public DelayedStreamPipeline addDelayedStream(Stream source, long delay) {
    // Create a new DelayedStreamPipeline object
    DelayedStreamPipeline pipeline = new DelayedStreamPipeline(source);

    // Add the delay to the elements of the source stream
    pipeline.addDelay(delay);

    // Return the modified DelayedStreamPipeline object
    return pipeline;
}
