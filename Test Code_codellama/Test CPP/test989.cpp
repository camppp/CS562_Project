c
#define ID1 (0x10000064)
#define ID2 (0x10000068)

uint32_t BoardGetRandomSeed(void)
{
    uint32_t seed;
    seed = (*(uint32_t *)ID1) ^ (*(uint32_t *)ID2);
    return seed;
}
