
# Largest Number Problem (LeetCode 179)

## Problem Description

Given a list of non-negative integers `nums`, arrange them such that they form the largest number and return it as a string. The result may be very large, so returning a string instead of an integer is necessary.

### Examples

- **Example 1:**
  - Input: `nums = [10, 2]`
  - Output: `"210"`

- **Example 2:**
  - Input: `nums = [3, 30, 34, 5, 9]`
  - Output: `"9534330"`

### Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^9`

---

## Approach

### C++ Solution

```cpp
class Solution {
public:
    static bool compare(string& a, string& b) { 
        return a + b > b + a; 
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        string answer;

        // Convert all integers to strings
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        // Sort the strings based on custom comparator
        sort(numStrs.begin(), numStrs.end(), compare);

        // Edge case: If the largest number is '0'
        if (numStrs[0] == "0")
            return "0";

        // Concatenate sorted strings to form the largest number
        for (string s : numStrs)
            answer += s;

        return answer;
    }
};
```

#### Explanation:

1. **Convert integers to strings**: All integers are converted to strings so that they can be compared based on their concatenated values.
2. **Custom sorting**: A comparator function sorts the numbers based on which combination (`a + b` vs `b + a`) forms a larger number.
3. **Edge case handling**: If the largest number is `0`, return `"0"`.
4. **Concatenation**: Concatenate the sorted strings to form the largest number.

---

### Python Solution

```python
from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(i) for i in nums]
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a+b < b+a else -1))
        return "0" if nums[0] == "0" else "".join(nums)
```

#### Explanation:

1. **Convert integers to strings**: Convert each integer in the list to a string to compare them based on concatenated values.
2. **Custom sorting**: Use `cmp_to_key` to implement a custom comparator that sorts the numbers in such a way that their concatenation results in the largest number.
3. **Edge case handling**: If the largest number is `0`, return `"0"`.
4. **Concatenation**: Join the sorted strings to form the largest number.

---

## Time Complexity

Both solutions have a time complexity of `O(n log n)` due to the sorting process. Here, `n` is the number of elements in the list `nums`.

---

## Space Complexity

The space complexity is `O(n)` since both solutions create an additional list of strings.
