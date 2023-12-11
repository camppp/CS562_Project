@Inject(method = "randomTick", at = @At("TAIL"), cancellable = true)
public void cancelRandomTick(BlockState state, ServerWorld world, BlockPos pos, Random random, CallbackInfo ci) {
    // Check if the block at the given position meets certain criteria
    if (state.getBlock() == Blocks.DIRT && world.getLightLevel(pos) > 8) {
        // If the block is dirt and the light level at the position is greater than 8, cancel the random tick
        repeat = true;
    }
}