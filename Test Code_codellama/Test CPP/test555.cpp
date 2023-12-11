#include "Civilization.hpp"

class Bubble
{
public:
    static void BubbleSort(Civilization* civilizations, int numCivilizations)
    {
        for (int i = 0; i < numCivilizations - 1; i++)
        {
            for (int j = i + 1; j < numCivilizations; j++)
            {
                if (civilizations[i].population > civilizations[j].population)
                {
                    Civilization temp = civilizations[i];
                    civilizations[i] = civilizations[j];
                    civilizations[j] = temp;
                }
            }
        }
    }
};
