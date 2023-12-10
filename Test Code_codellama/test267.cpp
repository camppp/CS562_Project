c
#define CUSTOM_ASSERT_EQ(v1, v2, testColor) \
    do { \
        if (v1.pos.x != v2.pos.x || v1.pos.y != v2.pos.y || v1.pos.z != v2.pos.z || \
            v1.uv0.x != v2.uv0.x || v1.uv0.y != v2.uv0.y || \
            v1.color0.x != v2.color0.x || v1.color0.y != v2.color0.y || v1.color0.z != v2.color0.z) { \
            printf("Vertex comparison failed: v1 = %f, %f, %f, uv0 = %f, %f, color0 = %f, %f, %f\n", \
                v1.pos.x, v1.pos.y, v1.pos.z, v1.uv0.x, v1.uv0.y, v1.color0.x, v1.color0.y, v1.color0.z); \
            printf("Vertex comparison failed: v2 = %f, %f, %f, uv0 = %f, %f, color0 = %f, %f, %f\n", \
                v2.pos.x, v2.pos.y, v2.pos.z, v2.uv0.x, v2.uv0.y, v2.color0.x, v2.color0.y, v2.color0.z); \
            printf("Test color = %f, %f, %f\n", testColor.x, testColor.y, testColor.z); \
            assert(false); \
        } \
    } while (0)
