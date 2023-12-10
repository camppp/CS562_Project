#include "C64CharMulti.h"
#include "C64Bitmap.h"
#include "CViewC64VicDisplay.h"

class C64CharMulti : public C64Bitmap
{
public:
    C64CharMulti(CViewC64VicDisplay* display, int x, int y) : C64Bitmap(display, x, y) {}

    // Set the pixel data for a multi-bitmap character
    void setPixelData(const std::vector<std::vector<int>>& pixelData)
    {
        // Check if the pixel data is valid
        if (pixelData.size() == 0 || pixelData[0].size() == 0)
        {
            throw std::invalid_argument("Invalid pixel data");
        }

        // Set the pixel data for the multi-bitmap character
        for (int y = 0; y < pixelData.size(); y++)
        {
            for (int x = 0; x < pixelData[y].size(); x++)
            {
                setPixel(x, y, pixelData[y][x]);
            }
        }
    }

    // Get the pixel data for a multi-bitmap character
    std::vector<std::vector<int>> getPixelData() const
    {
        std::vector<std::vector<int>> pixelData;

        // Get the pixel data for the multi-bitmap character
        for (int y = 0; y < getHeight(); y++)
        {
            std::vector<int> row;
            for (int x = 0; x < getWidth(); x++)
            {
                row.push_back(getPixel(x, y));
            }
            pixelData.push_back(row);
        }

        return pixelData;
    }

    // Render the multi-bitmap character on the C64 VIC display
    void render()
    {
        // Get the pixel data for the multi-bitmap character
        std::vector<std::vector<int>> pixelData = getPixelData();

        // Set the pixel data for the multi-bitmap character on the C64 VIC display
        for (int y = 0; y < pixelData.size(); y++)
        {
            for (int x = 0; x < pixelData[y].size(); x++)
            {
                display->setPixel(x + getX(), y + getY(), pixelData[y][x]);
            }
        }
    }

private:
    // The CViewC64VicDisplay object that the multi-bitmap character is rendered on
    CViewC64VicDisplay* display;

    // The x and y coordinates of the multi-bitmap character on the C64 VIC display
    int x, y;
};
