#include <stdlib.h>

typedef struct {
    unsigned int z1;
    unsigned int z2;
    unsigned int z3;
    unsigned int s1;
    unsigned int s2;
    unsigned int s3;
    unsigned int b;
} TauswortheGenerator;

TauswortheGenerator prop;

void initializeTauswortheGenerator(unsigned int globalSeed) {
    srand(globalSeed);
    prop.z1 = rand();
    prop.z2 = rand();
    prop.z3 = rand();
    prop.s1 = 13;
    prop.s2 = 19;
    prop.s3 = 12;
    prop.b = 0xFFFFFFFF;
}

unsigned int generateRandomNumber() {
    prop.z1 = ((prop.z1 << prop.s1) ^ prop.z1) & prop.b;
    prop.z2 = ((prop.z2 << prop.s2) ^ prop.z2) & prop.b;
    prop.z3 = ((prop.z3 << prop.s3) ^ prop.z3) & prop.b;
    return (prop.z1 ^ prop.z2 ^ prop.z3);
}
