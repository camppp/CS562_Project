public class DumpLavaFurnace {

    private static final int FURNACE_TOP_SLOT = 0;

    public void dumpLavaIntoFurnace(ServerWorld world, FluidStack fluidStack) {
        // Get the furnace's inventory
        IInventory furnaceInventory = getFurnaceInventory(world);

        // Check if the furnace's top slot is empty
        if (furnaceInventory.getStackInSlot(FURNACE_TOP_SLOT).isEmpty()) {
            // If it is, insert the lava into the top slot
            furnaceInventory.insertFluid(fluidStack, FURNACE_TOP_SLOT, true, null);
        }
    }

    public void smeltItems(ServerWorld world) {
        // Get the furnace's inventory
        IInventory furnaceInventory = getFurnaceInventory(world);

        // Check if the furnace's top slot contains lava
        if (furnaceInventory.getStackInSlot(FURNACE_TOP_SLOT).getFluid().getFluid() == Fluids.LAVA) {
            // If it does, start the furnace's smelting process
            startSmelting(world, furnaceInventory);
        }
    }

    private IInventory getFurnaceInventory(ServerWorld world) {
        // Get the furnace's position
        BlockPos furnacePos = getFurnacePosition(world);

        // Get the furnace's block entity
        BlockEntity blockEntity = world.getBlockEntity(furnacePos);

        // Check if the block entity is a furnace
        if (blockEntity instanceof AbstractFurnaceBlockEntity) {
            // If it is, return the furnace's inventory
            return ((AbstractFurnaceBlockEntity) blockEntity).getInventory();
        }

        // If the block entity is not a furnace, return null
        return null;
    }

    private BlockPos getFurnacePosition(ServerWorld world) {
        // Implement logic to get the position of the furnace
        // This could involve searching for the nearest furnace in the world
        return null;
    }

    private void startSmelting(ServerWorld world, IInventory furnaceInventory) {
        // Implement logic to start the furnace's smelting process
        // This could involve calling the furnace's smelt method
    }
}