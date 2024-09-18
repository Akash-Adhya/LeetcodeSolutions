#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


class Solution {
public:
    static bool compare(string& a, string& b) { 
        return a + b > b + a; 
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        string answer;

        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        sort(numStrs.begin(), numStrs.end(), compare);

        if (numStrs[0] == "0")
            return "0";

        for (string s : numStrs)
            answer += s;
        return answer;
    }
};