
# LeetCode Problem: 539. Minimum Time Difference

## Problem Description

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time points in the list.

### Example 1:
- **Input**: `timePoints = ["23:59","00:00"]`
- **Output**: `1`

### Example 2:
- **Input**: `timePoints = ["00:00","23:59","00:00"]`
- **Output**: `0`

### Constraints:
- `2 <= timePoints.length <= 2 * 10^4`
- `timePoints[i]` is in the format `"HH:MM"`.

## Approach

To solve this problem, we aim to minimize the time difference between any two time points, considering that the clock is circular (i.e., 00:00 comes after 23:59).

### Step-by-Step Approach:

1. **Convert Time to Minutes**:
   We first convert all time points from "HH:MM" format into minutes, where:
   - Hours are multiplied by 60.
   - The total minutes for each time point are calculated as `hours * 60 + minutes`.

2. **Sort the Time Points**:
   We sort the list of minutes. This makes it easier to calculate the difference between consecutive time points.

3. **Calculate the Minimum Difference**:
   - We calculate the difference between consecutive time points in the sorted list.
   - We also handle the circular nature of the clock by comparing the last time point with the first (i.e., the difference between `23:59` and `00:00`).
   - For each pair, we check if the difference is larger than half a day (720 minutes) and adjust accordingly (since the circular nature means smaller differences may occur by wrapping around the day).

4. **Return the Minimum Difference**:
   After iterating through all consecutive time points and checking the circular difference, the smallest difference is returned.

## C++ Solution

```cpp
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

int main() {
    vector<string> timePoints = {"00:00", "04:00", "22:00"};
    Solution obj;
    cout << obj.findMinDifference(timePoints);
    return 0;
}
```

## Time Complexity

- **Time Complexity**: The time complexity of the solution is dominated by the sorting step, which is **O(n log n)**, where `n` is the number of time points. 
    - Parsing the time points into minutes takes **O(n)**.
    - Sorting the time points takes **O(n log n)**.
    - Calculating the minimum difference after sorting takes **O(n)**.

Thus, the overall time complexity is **O(n log n)**.

## Space Complexity

- **Space Complexity**: The space complexity is **O(n)** since we store the converted time points in minutes in an array.

## Conclusion

This solution efficiently handles the problem of finding the minimum time difference between time points by converting them into minutes, sorting the times, and considering the circular nature of a 24-hour day. The approach is optimized for large input sizes, balancing time and space complexities effectively.
