#include "./Civilization.hpp"
#include "Bubble.hpp"

namespace Emperor2
{
    Civilization *Bubble::BubbleSort(Civilization *civilizations, int numberOfCivilizations)
    {
        for (int i = 0; i < numberOfCivilizations - 1; i++)
        {
            for (int j = 0; j < numberOfCivilizations - i - 1; j++)
            {
                if (civilizations[j].population > civilizations[j + 1].population)
                {
                    // Swap civilizations[j] and civilizations[j+1]
                    Civilization temp = civilizations[j];
                    civilizations[j] = civilizations[j + 1];
                    civilizations[j + 1] = temp;
                }
            }
        }
        return civilizations;
    }
} // namespace Emperor2
