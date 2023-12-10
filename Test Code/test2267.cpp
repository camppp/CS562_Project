#include <stdio.h>

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
} ParticleData;

void readHexa(FILE *fp) {
    PS::F64 (*cvt)(PS::U64) = convertU64ToF64;
    PS::U64 umass;
    PS::U64 upos[3], uvel[3], uacc[3];

    while (fscanf(fp, "%llx", &umass) != EOF) {
        for (int i = 0; i < 3; i++) {
            fscanf(fp, "%llx", &upos[i]);
        }
        for (int i = 0; i < 3; i++) {
            fscanf(fp, "%llx", &uvel[i]);
        }
        for (int i = 0; i < 3; i++) {
            fscanf(fp, "%llx", &uacc[i]);
        }

        ParticleData particle;
        particle.mass = cvt(umass);
        for (int i = 0; i < 3; i++) {
            particle.position[i] = cvt(upos[i]);
            particle.velocity[i] = cvt(uvel[i]);
            particle.acceleration[i] = cvt(uacc[i]);
        }

        // Process the particle data or store it in a suitable data structure
        // For example, you can store the particle data in an array or a linked list for further processing
    }
}
