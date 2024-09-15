#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int findTheLongestSubstring(const string &s) {
    int maxLen = 0, cur = 0;
    unordered_map<int, int> seen = {{0, -1}};  // To track the current bitmask and index
    
    for (int i = 0; i < s.length(); ++i) {
        // Use a switch-case to handle vowels instead of an unordered_map
        switch (s[i]) {
            case 'a': cur ^= 1 << 0; break;
            case 'e': cur ^= 1 << 1; break;
            case 'i': cur ^= 1 << 2; break;
            case 'o': cur ^= 1 << 3; break;
            case 'u': cur ^= 1 << 4; break;
        }

        // If the current bitmask has been seen before, calculate the possible maximum length
        if (seen.count(cur)) {
            maxLen = max(maxLen, i - seen[cur]);
        } else {
            // Otherwise, store the index of this bitmask
            seen[cur] = i;
        }
    }

    return maxLen;
}

int main() {
    string s = "eleetminicoworoep";
    cout << "The longest substring length is: " << findTheLongestSubstring(s) << endl;
    return 0;
}
