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
