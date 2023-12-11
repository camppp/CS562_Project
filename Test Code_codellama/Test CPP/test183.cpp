void simulateBoot(Processor* processor, RAM* ram, HardDisk* hd) {
    // Freeze the processor
    processor->freeze();

    // Load the boot sector from the hard disk
    string bootSector = hd->read(BOOT_SECTOR, 1);

    // Load the boot code into the RAM
    ram->load(BOOT_ADDRESS, bootSector);

    // Jump to the boot address
    processor->jump(BOOT_ADDRESS);

    // Execute the boot code
    processor->execute();
}
