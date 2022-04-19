// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        ans.reserve(n);
        int l;
        while(n--) {
            l = max(1, k - 26 * n); 
            k -= l;
            ans.push_back(l - 1 + 'a'); 
        }
        return ans;
    }
};