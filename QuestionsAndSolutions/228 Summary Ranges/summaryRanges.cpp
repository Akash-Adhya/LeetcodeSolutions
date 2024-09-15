#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        vector<string> result;
        int lower = nums[0];
        int upper = nums[0];

        if (nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }

        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i] == (nums[i - 1] + 1))
            {
                upper = nums[i];
            }
            else
            {
                if (upper == lower)
                {
                    result.push_back(to_string(upper));
                }
                else
                {
                    result.push_back(to_string(lower) + "->" + to_string(upper));
                }
                lower = nums[i];
                upper = nums[i];
            }
        }

        if (upper == lower)
        {
            result.push_back(to_string(upper));
        }
        else
        {
            result.push_back(to_string(lower) + "->" + to_string(upper));
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = obj.summaryRanges(nums);

    // Output the result
    for (const string &range : result)
    {
        cout << range << endl;
    }

    return 0;
}
