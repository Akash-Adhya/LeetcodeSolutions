# 1371. Find the Longest Substring Containing Vowels in Even Counts

## Problem Description

Given the string `s`, return the size of the longest substring containing each vowel an even number of times. The vowels are: `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they must each appear an even number of times in the substring.

### Examples

#### Example 1:
- **Input:** `s = "eleetminicoworoep"`
- **Output:** `13`
- **Explanation:** The longest substring is `"leetminicowor"` which contains two of each of the vowels: `e`, `i`, and `o`, and zero of the vowels: `a` and `u`.

#### Example 2:
- **Input:** `s = "leetcodeisgreat"`
- **Output:** `5`
- **Explanation:** The longest substring is `"leetc"` which contains two `e's`.

#### Example 3:
- **Input:** `s = "bcbcbc"`
- **Output:** `6`
- **Explanation:** In this case, the given string `"bcbcbc"` is the longest because all vowels: `a`, `e`, `i`, `o`, and `u` appear zero times.

### Constraints
- `1 <= s.length <= 5 x 10^5`
- `s` contains only lowercase English letters.

## Approach

To solve this problem, we need to find the longest substring where the number of times each vowel (`a`, `e`, `i`, `o`, `u`) appears is even. This can be efficiently solved using a **bitmasking** technique, where we maintain a bitmask that keeps track of the parity (even or odd) of the count of vowels as we traverse the string.

### Explanation of the Approach

1. We initialize a variable `cur` to represent the current state of the vowel counts (whether they are even or odd). The state is encoded in the lower 5 bits of an integer, where each bit corresponds to a vowel (`a`, `e`, `i`, `o`, `u`).
   
2. We maintain a map `seen` that stores the first occurrence of each state (bitmask). This allows us to efficiently calculate the longest substring.

3. As we iterate through the string `s`, we update the state based on the current character:
   - If the character is a vowel, we toggle the corresponding bit in the bitmask.
   
4. If the current state has been seen before, the substring between the first occurrence of this state and the current index has an even number of each vowel. We update the maximum length accordingly.

5. If the state hasn't been seen before, we store its first occurrence.

### Code

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int maxLen = 0, cur = 0;
        unordered_map<int, int> seen = {{0, -1}};

        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
            case 'a':
                cur ^= 1 << 0;
                break;
            case 'e':
                cur ^= 1 << 1;
                break;
            case 'i':
                cur ^= 1 << 2;
                break;
            case 'o':
                cur ^= 1 << 3;
                break;
            case 'u':
                cur ^= 1 << 4;
                break;
            }

            if (seen.count(cur)) {
                maxLen = max(maxLen, i - seen[cur]);
            } else {
                seen[cur] = i;
            }
        }

        return maxLen;
    }
};  
```

## Complexity Analysis:

### Time Complexity:
    O(n): We iterate over the string s of length n exactly once. Each character in the string is processed in constant time because:
    Updating the bitmask for the vowels is an O(1) operation.
    Checking the map seen and updating it is also an O(1) operation due to the hash map's average case constant time complexity for insert and lookup.
    Thus, the overall time complexity is O(n).

### Space Complexity:
    O(1) for storing the bitmask since it requires only 5 bits (one for each vowel).
    O(min(n, 32)) for storing the map seen. In the worst case, there are at most 32 different bitmask values (since 2^5 = 32), but in practice, the space is bounded by the length of the string n.
    Thus, the space complexity can be considered O(n) in the worst case due to the size of the map.

## Conclusion
This problem is an excellent example of using bitmasking to solve a complex substring problem in linear time. By keeping track of the state of vowel counts using a bitmask and leveraging a map to store the first occurrence of each state, we can efficiently compute the longest substring with even counts of vowels. This approach ensures that the solution runs efficiently even for the largest inputs.
