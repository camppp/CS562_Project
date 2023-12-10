#include <iostream>

struct Vertex {
  struct {
    float x, y, z;
  } pos;
  struct {
    float x, y;
  } uv0;
  struct {
    float x, y, z;
  } color0;
};

#define CUSTOM_ASSERT_EQ(actual, expected) \
  do { \
    if (actual != expected) { \
      std::cerr << "Assertion failed: " #actual " != " #expected << std::endl; \
      std::cerr << "  " #actual " = " << actual << std::endl; \
      std::cerr << "  " #expected " = " << expected << std::endl; \
    } \
  } while (0)

int main() {
  Vertex v1 = {{1.0f, 2.0f, 3.0f}, {0.5f, 0.7f}, {0.1f, 0.2f, 0.3f}};
  Vertex v2 = {{1.0f, 2.0f, 3.0f}, {0.5f, 0.7f}, {0.1f, 0.2f, 0.3f}};
  Vertex testColor = {{0.1f, 0.2f, 0.3f}};

  CUSTOM_ASSERT_EQ(v2.pos.x, v1.pos.x);
  CUSTOM_ASSERT_EQ(v2.pos.y, v1.pos.y);
  CUSTOM_ASSERT_EQ(v2.pos.z, v1.pos.z);
  CUSTOM_ASSERT_EQ(v2.uv0.x, v1.uv0.x);
  CUSTOM_ASSERT_EQ(v2.uv0.y, v1.uv0.y);
  CUSTOM_ASSERT_EQ(v2.color0.x, testColor.pos.x);
  CUSTOM_ASSERT_EQ(v2.color0.y, testColor.pos.y);
  CUSTOM_ASSERT_EQ(v2.color0.z, testColor.pos.z);

  return 0;
}
