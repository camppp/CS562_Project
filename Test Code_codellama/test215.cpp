    lis r3, 0x1234
    ori r3, r3, 0x5678
    stw r3, 0(r4)
    lwz r5, 0(r4)
    addi r6, r5, 0x10
    stw r6, 0(r4)
    lwz r7, 0(r4)
    addi r7, r7, 0x10
    stw r7, 0(r4)
    lwz r8, 0(r4)
    addi r8, r8, 0x10
    stw r8, 0(r4)
