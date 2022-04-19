// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<char> odds;
        vector<char> evens;
        for (char c : s) {
            if ((c -'0')%2 == 0) {
                evens.push_back(c);
            } else {
                odds.push_back(c);
            }
        }
        string ret;
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int i = (int)odds.size()-1;
        int j = (int)evens.size()-1;
        for (char c : s) {
            if ((c-'0')%2 == 1) {
                ret.push_back(odds[i--]);
            } else {
                ret.push_back(evens[j--]);
            }
        }
        return stoi(ret);
    }
};