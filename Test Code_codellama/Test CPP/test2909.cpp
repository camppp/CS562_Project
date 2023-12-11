c
float calculateDistance(float off_x, float off_y, float off_z, float POLY_cam_x, float POLY_cam_y, float POLY_cam_z) {
    float input_vx = off_x - POLY_cam_x;
    float input_vy = off_y - POLY_cam_y;
    float input_vz = off_z - POLY_cam_z;

    float distance = sqrt(input_vx * input_vx + input_vy * input_vy + input_vz * input_vz);

    return distance;
}
