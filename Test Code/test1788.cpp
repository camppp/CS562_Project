#include <iostream>
#include <vector>
#include <string>

int calculateTotalSum(const std::string& beg, const std::vector<int>& tempPath)
{
    int totalSum = 0;

    for (int i = 0; i < tempPath.size(); i++)
    {
        totalSum += tempPath[i];
    }

    return totalSum;
}

int main()
{
    std::vector<int> path = {1, 2, 3, 4, 5};
    std::string start = "1";

    int sum = calculateTotalSum(start, path);
    std::cout << "Total sum of integers in the path: " << sum << std::endl;

    return 0;
}
