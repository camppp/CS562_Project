@Inject(method = "randomTick", at = @At("TAIL"), cancellable = true)
public void cancelRandomTick(BlockState state, ServerWorld world, BlockPos pos, Random random, CallbackInfo ci) {
    // Check if the block at the given position meets certain criteria
    if (meetsCriteria(state, world, pos)) {
        // If the block meets the criteria, cancel the random tick
        ci.cancel();
        // Set the repeat variable to true to indicate that the random tick should not occur for this block
        repeat = true;
    }
}

// Method to check if the block at the given position meets certain criteria
private boolean meetsCriteria(BlockState state, ServerWorld world, BlockPos pos) {
    // Replace this with your own logic to check if the block meets the criteria
    // For example, you could check if the block is a specific type of block
    return state.getBlock() instanceof YourSpecificBlock;
}