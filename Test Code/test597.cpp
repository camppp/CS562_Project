c
int processEventPackers(int* eventIds, int numEvents, int* packSeq)
{
    int missing_packer = 0;
    for (int i = 0; i < numEvents; i++)
    {
        int id = eventIds[i];
        bool packer_found = false;
        // ... (code to find the appropriate packer for the sub event id)
        if (!packer_found)
        {
            fprintf(stderr, "Failed to find unpacker for sub event id 0x%08x\n", id);
            fflush(stderr);
            missing_packer++;
        }
        else
        {
            packSeq[i] = packer_found;
        }
    }
    return missing_packer;
}
