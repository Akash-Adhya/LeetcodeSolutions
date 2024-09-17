
# Leetcode Problem: 884. Uncommon Words from Two Sentences

## Problem Description

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is considered **uncommon** if it appears **exactly once** in one of the sentences and does not appear in the other sentence.

Given two sentences `s1` and `s2`, the task is to return a list of all uncommon words. The order of the result doesn't matter.

### Example 1:
```
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
```
Explanation: 
- The word "sweet" appears only in `s1`, while the word "sour" appears only in `s2`.

### Example 2:
```
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
```
Explanation: 
- The word "banana" appears only in `s2`, and "apple" appears more than once in `s1`.

### Constraints:
- `1 <= s1.length, s2.length <= 200`
- `s1` and `s2` consist of lowercase English letters and spaces.
- There are no leading or trailing spaces.
- All words in `s1` and `s2` are separated by a single space.

## Approach for the Solution for python

1. **Split the Sentences into Lists**:
   - The input sentences `s1` and `s2` are split into individual words using the `split()` method, which creates two separate lists: `s1List` and `s2List`.

2. **Count Word Occurrences in Each Sentence**:
   - For each word in `s1List`, check if it appears only once in `s1List` using the `count()` method.
   - If the word appears exactly once in `s1List` and **does not** appear in `s2List`, it is considered an uncommon word and added to the `answer` list.

3. **Check Uncommon Words in the Second Sentence**:
   - Repeat the same process for `s2List`. For each word in `s2List`, check if it appears only once in `s2List` and **does not** appear in `s1List`. If both conditions hold true, add the word to the `answer` list.

4. **Return the Result**:
   - Finally, return the `answer` list containing all the uncommon words from both sentences.


## Python Solution

```python

class Solution:

    def uncommonFromSentences(self, s1: str, s2: str) -> list[str]:
        answer = []

        s1List = s1.split(" ")
        s2List = s2.split(" ")

        for elem in s1List:
            if s1List.count(elem) == 1 :
                if elem not in s2List:
                    answer.append(elem)

        for elem in s2List:
            if s2List.count(elem) == 1 :
                if elem not in s1List:
                    answer.append(elem)

        return answer

obj= Solution()
ans = obj.uncommonFromSentences("This is an apple", "This is a banana")
print(ans)

```

## Approach for the C++ Solution

1. **Combine Sentences**:
   - The two input sentences `s1` and `s2` are concatenated with a space in between to create a single combined string.

2. **Count Word Occurrences**:
   - A `stringstream` is used to process the combined string word by word.
   - An `unordered_map` is utilized to store the frequency of each word as the combined string is split into individual words. Each word is inserted into the map, and its frequency is incremented.

3. **Find Uncommon Words**:
   - After processing all the words, the program iterates through the `unordered_map`.
   - Words that appear exactly once in the map are considered uncommon and added to the result vector.

4. **Return and Output the Result**:
   - The result vector, containing the uncommon words, is returned. These words are then printed as output.

### Explanation:

- **Data Structure**: The C++ solution uses an `unordered_map` to count the frequency of each word. This allows for efficient insertion and lookup operations with an average time complexity of O(1) per operation.
  
- **Word Splitting**: A `stringstream` is used to easily split the combined sentence into words. This is a convenient way to handle splitting based on spaces in C++.

- **Efficiency**: 
   - The program runs in **O(n)** time complexity, where `n` is the total number of words in both sentences. This is because each word is processed once to count its occurrences and once more to check for uncommon words.
   - The space complexity is also **O(n)**, as we store all the words and their frequencies in the map.


## C++ Solution

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        
        stringstream combined(s1 + " " + s2);
        string word;

        while (combined >> word) {
            wordCount[word]++;
        }

        for (auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};

int main() {
    Solution obj;
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    
    vector<string> ans = obj.uncommonFromSentences(s1, s2);
    
    cout << "Uncommon words: ";
    for (const string& word : ans) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

```




### Time Complexity
- The time complexity of this approach is **O(n)**, where `n` is the total number of words in both sentences combined. We split the string and traverse it to build the word count, and then we iterate through the map to find the uncommon words.

### Space Complexity
- The space complexity is **O(n)**, as we store all the words and their frequencies in the hash map.

## Conclusion
This solution efficiently solves the problem by utilizing a hash map to track word occurrences, ensuring a linear time complexity while processing the words from both sentences.
