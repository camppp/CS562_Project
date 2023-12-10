#include <iostream>
#include <string>
#include "mapBuilder.h"  // Assuming the mapBuilder object is defined in a separate header file

void saveMappingData(bool SAVE_POSE_LOG, const std::string& OUT_DIR, int LOG_FREQUENCY, bool SAVE_3D_SCENE, int step, MapBuilder& mapBuilder) {
    if (SAVE_POSE_LOG) {
        std::cout << "Saving pose log information...";
        mapBuilder.getCurrentPoseEstimation()->saveToTextFile(OUT_DIR + "/mapbuild_posepdf_" + std::to_string(step) + ".txt");
        std::cout << "Ok\n";
    }

    if (step % LOG_FREQUENCY == 0 || SAVE_3D_SCENE) {
        CPose3D robotPose;  // Assuming CPose3D is the type for robot pose
        // Save 3D scene view logic here based on the requirements
        // Example: mapBuilder.save3DSceneView(robotPose, OUT_DIR + "/3d_scene_" + std::to_string(step) + ".txt");
    }
}
