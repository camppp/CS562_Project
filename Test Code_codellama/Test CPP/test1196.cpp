void depthData2point(const DepthData& depth, const IntrinsicParams& params, std::vector<Point3D>& points) {
    // Calculate the depth value for each pixel in the depth map
    for (int i = 0; i < depth.width; i++) {
        for (int j = 0; j < depth.height; j++) {
            float depthValue = depth.data[i][j];
            // Calculate the 3D point for each pixel
            Point3D point;
            point.x = (i - params.cx) * depthValue / params.fx;
            point.y = (j - params.cy) * depthValue / params.fy;
            point.z = depthValue;
            points.push_back(point);
        }
    }
}
