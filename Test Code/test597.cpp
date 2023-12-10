#include <stdio.h>
#include <stdbool.h>

void findPacker(int id, bool* packer_found, int* packSeq)
{
    // Example logic to find the appropriate packer for the sub event id
    if (id % 2 == 0)
    {
        *packer_found = true;
        *packSeq = 1;  // Example packer sequence for even sub event ids
    }
    else
    {
        *packer_found = true;
        *packSeq = 2;  // Example packer sequence for odd sub event ids
    }
}

int processEventPackers(int* eventIds, int numEvents, int* packSeq)
{
    int missing_packer = 0;
    for (int i = 0; i < numEvents; i++)
    {
        int id = eventIds[i];
        bool packer_found = false;
        findPacker(id, &packer_found, &packSeq[i]);
        if (!packer_found)
        {
            fprintf(stderr, "Failed to find unpacker for sub event id 0x%08x\n", id);
            fflush(stderr);
            missing_packer++;
        }
    }
    return missing_packer;
}
