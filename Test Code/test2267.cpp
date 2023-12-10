c
void readParticleData(FILE *fp) {
    PS::F64 (*cvt)(PS::U64) = convertU64ToF64;
    PS::U64 umass;
    PS::U64 upos[3], uvel[3], uacc[3];

    while (fread(&umass, sizeof(PS::U64), 1, fp) == 1) {
        fread(&upos[0], sizeof(PS::U64), 3, fp);
        fread(&uvel[0], sizeof(PS::U64), 3, fp);
        fread(&uacc[0], sizeof(PS::U64), 3, fp);

        // Convert the hexadecimal data to the appropriate data types
        PS::F64 mass = cvt(umass);
        PS::F64 pos[3] = {cvt(upos[0]), cvt(upos[1]), cvt(upos[2])};
        PS::F64 vel[3] = {cvt(uvel[0]), cvt(uvel[1]), cvt(uvel[2])};
        PS::F64 acc[3] = {cvt(uacc[0]), cvt(uacc[1]), cvt(uacc[2])};

        // Store the particle data in a suitable data structure
        ParticleData data;
        data.mass = mass;
        data.position = pos;
        data.velocity = vel;
        data.acceleration = acc;
        particleData.push_back(data);
    }
}
