void ByteSwapCommandHeader(CommandHeader* pCommandHeader) {
    pCommandHeader->CommandId = ByteSwapShort(pCommandHeader->CommandId);
    for (int i = 0; i < MACHINE_ID_SIZE; i++) {
        pCommandHeader->DestMachineId[i] = ByteSwapByte(pCommandHeader->DestMachineId[i]);
        pCommandHeader->SrcMachineId[i] = ByteSwapByte(pCommandHeader->SrcMachineId[i]);
    }
}
