sharp
void UpdateClassificationTable(int predictedValue, int trueValue, int[] classificationTable)
{
    if (predictedValue == trueValue)
    {
        classificationTable[predictedValue]++;
    }
}
