#include <yoga/Yoga.h>

static float _baselineFunc(YGNodeRef node, float width, float height) {
  // Calculate the baseline position based on the node's dimensions
  float baseline = node->getComputedStyle().baseline;
  if (baseline == YG_AUTO) {
    // If the baseline is set to auto, calculate it based on the node's font size
    baseline = node->getComputedStyle().fontSize;
  }
  return baseline;
}
