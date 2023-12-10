void ByteSwapCommandHeader(CommandHeader* pCommandHeader) {
    // Swap the byte order of the CommandId field
    pCommandHeader->CommandId = ByteSwapShort(pCommandHeader->CommandId);

    // Swap the byte order of each element in the DestMachineId and SrcMachineId arrays
    for (int i = 0; i < MACHINE_ID_SIZE; i++) {
        pCommandHeader->DestMachineId[i] = ByteSwapByte(pCommandHeader->DestMachineId[i]);
        pCommandHeader->SrcMachineId[i] = ByteSwapByte(pCommandHeader->SrcMachineId[i]);
    }
}
