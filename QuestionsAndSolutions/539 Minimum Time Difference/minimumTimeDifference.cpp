#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int minimum = INT_MAX;
        int diff = 0;

        for (auto& value : timePoints) {
            int hours = 10 * (int(value[0])) + int(value[1]);
            int min = 10 * (int(value[3])) + int(value[4]);
            minutes.push_back(((hours * 60) + min));
        }

        sort(minutes.begin(), minutes.end());

        for (int i = 0; i < (minutes.size() - 1); i++) {

            diff = abs(minutes[i] - minutes[i + 1]);
            if (diff > 720) {
                diff = abs(diff - 1440);
            }

            if (minimum > diff) {
                minimum = diff;
            }
        }
        int temp = abs(minutes[minutes.size() - 1] - minutes[0]);
        diff = temp > 720 ? abs(temp - 1440) : temp;
        if (minimum > diff)
            minimum = diff;

        return minimum;
    }
};


int main()
{
    vector<string> timePoints = {"00:00", "04:00", "22:00"};
    Solution obj;
    cout << obj.findMinDifference(timePoints);

    return 0;
}