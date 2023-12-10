#include <cstdint>

enum HgiCullMode {
    HgiCullModeCount, // Assuming this is the enum definition
    HgiPolygonModeFill,
    HgiPolygonModeLine,
    HgiPolygonModePoint
};

enum HgiBlendOp {
    HgiBlendOpCount, // Assuming this is the enum definition
    HgiBlendOpAdd,
    HgiBlendOpSubtract,
    HgiBlendOpReverseSubtract
};

enum GL_POLYGON_MODE {
    GL_FILL,
    GL_LINE,
    GL_POINT
};

enum GL_BLEND_EQUATION {
    GL_FUNC_ADD,
    GL_FUNC_SUBTRACT,
    GL_FUNC_REVERSE_SUBTRACT
};

static const uint32_t
_PolygonModeTable[HgiCullModeCount][2] =
{
    {HgiPolygonModeFill,  GL_FILL},
    {HgiPolygonModeLine,  GL_LINE},
    {HgiPolygonModePoint, GL_POINT},
};

static uint32_t
_blendEquationTable[HgiBlendOpCount][2] =
{
    {HgiBlendOpAdd, GL_FUNC_ADD},
    {HgiBlendOpSubtract, GL_FUNC_SUBTRACT},
    {HgiBlendOpReverseSubtract, GL_FUNC_REVERSE_SUBTRACT}
};

uint32_t ConvertEnumValue(uint32_t inputEnumValue, uint32_t enumType) {
    if (enumType == HgiCullMode) {
        for (int i = 0; i < HgiCullModeCount; ++i) {
            if (_PolygonModeTable[i][0] == inputEnumValue) {
                return _PolygonModeTable[i][1];
            }
        }
    } else if (enumType == HgiBlendOp) {
        for (int i = 0; i < HgiBlendOpCount; ++i) {
            if (_blendEquationTable[i][0] == inputEnumValue) {
                return _blendEquationTable[i][1];
            }
        }
    }
    // Handle unrecognized enumType or inputEnumValue without a corresponding value
    return 0; // Or any appropriate default value or error code
}
