
# Summary Ranges

## Problem Description

The problem **Summary Ranges** requires us to return the smallest sorted list of ranges that cover all numbers in the array exactly.

- Each range `[a, b]` in the list should be output as:
  - `"a->b"` if `a != b`
  - `"a"` if `a == b`
  
### Example

#### Example 1:
**Input:** 
```cpp
nums = [0, 1, 2, 4, 5, 7]
```
**Output:** 
```cpp
["0->2", "4->5", "7"]
```
#### Example 2:
**Input:** 
```cpp
nums = [0, 2, 3, 4, 6, 8, 9]
```
**Output:** 
```cpp
["0", "2->4", "6", "8->9"]
```

## Approach

### 1. Initialize Variables
We start by initializing two variables:
- `lower`: which holds the start of the current range.
- `upper`: which holds the end of the current range.

### 2. Iterating through the Array
We iterate over the input array `nums`:
- If the current number is consecutive to the previous one (`nums[i] == nums[i-1] + 1`), we update `upper` to extend the current range.
- Otherwise, we:
  - Store the current range in the `result` vector.
  - Reset `lower` and `upper` to the current number.

### 3. Handling the Last Range
After the loop, the last range is added to the result, ensuring that any remaining numbers are included.

### 4. Edge Cases
- If the input array is empty, we return an empty result.
- If the input array contains a single number, we return that number as a string.

### Time Complexity
- The time complexity is **O(n)**, where **n** is the number of elements in the input array `nums`, since we iterate over the array once.

## Code Implementation

###CPP

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.size() == 0)
            return {};

        vector<string> result;
        int lower = nums[0];
        int upper = nums[0];

        if (nums.size() == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (nums[i - 1] + 1)) {
                upper = nums[i];
            } else {
                if (upper == lower) {
                    result.push_back(to_string(upper));
                } else {
                    result.push_back(to_string(lower) + "->" + to_string(upper));
                }
                lower = nums[i];
                upper = nums[i];
            }
        }

        if (upper == lower) {
            result.push_back(to_string(upper));
        } else {
            result.push_back(to_string(lower) + "->" + to_string(upper));
        }

        return result;
    }
};
```

## Conclusion

The solution efficiently processes the input array by grouping consecutive numbers into ranges. It handles all edge cases and runs in linear time relative to the input size.
