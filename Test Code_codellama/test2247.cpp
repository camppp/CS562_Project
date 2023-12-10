void saveFiles(bool SAVE_POSE_LOG, bool OUT_DIR, int LOG_FREQUENCY, bool SAVE_3D_SCENE, int step, MapBuilder& mapBuilder) {
    if (SAVE_POSE_LOG) {
        // Save the pose log information to a text file
        std::string filename = OUT_DIR + "/pose_log_" + std::to_string(step) + ".txt";
        std::ofstream file(filename);
        file << mapBuilder.getPoseEstimation();
        file.close();
    }

    if (SAVE_3D_SCENE && step % LOG_FREQUENCY == 0) {
        // Save a 3D scene view of the mapping process
        std::string filename = OUT_DIR + "/3d_scene_" + std::to_string(step) + ".png";
        mapBuilder.save3DScene(filename);
    }
}
