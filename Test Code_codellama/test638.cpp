#include <cmath>

void convertToRectangular(double dblParallelNorth, double dblParallelSouth, double dblAzimuth, double& dblRectifiedGrid) {
  // Calculate the rectangular coordinates
  dblRectifiedGrid = cos(dblParallelNorth) * cos(dblAzimuth);
  dblRectifiedGrid += cos(dblParallelSouth) * sin(dblAzimuth);
  dblRectifiedGrid += sin(dblParallelNorth) * cos(dblAzimuth);
}
