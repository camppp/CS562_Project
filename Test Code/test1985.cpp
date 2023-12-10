#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<int> shortestToChar(std::string &s, char c)
    {
        std::vector<int> res(s.size(), s.size());  // Initialize the result array with maximum possible distance
        int pos = -s.size();  // Initialize the position of the last occurrence of character c

        // Traverse the string from left to right
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == c)
                pos = i;  // Update the position of the last occurrence of character c

            res[i] = std::min(res[i], std::abs(i - pos));  // Update the distance to character c
        }

        // Traverse the string from right to left
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == c)
                pos = i;  // Update the position of the last occurrence of character c

            res[i] = std::min(res[i], std::abs(i - pos));  // Update the distance to character c
        }

        return res;
    }
};
