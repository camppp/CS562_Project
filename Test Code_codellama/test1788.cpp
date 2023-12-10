int calculateTotalSum(const std::string& beg, const std::vector<int>& tempPath)
{
    int totalSum = 0;
    for (int i = 0; i < tempPath.size(); i++)
    {
        if (tempPath[i] == beg)
        {
            totalSum += tempPath[i];
        }
    }
    return totalSum;
}
