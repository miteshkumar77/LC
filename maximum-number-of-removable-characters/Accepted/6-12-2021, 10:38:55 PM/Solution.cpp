// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    bool isSubsequence(string& s, string& p) {
        int i = 0;
        for (char c : s) {
            if (p[i] == c) ++i;
            if (i == p.length()) return true;
        }
        return false;
    }
    
    bool check(string s, string& p, vector<int>& removable, int k) {
        for (int i = 0; i < k; ++i) {
            s[removable[i]] = '_';
        }
        return isSubsequence(s, p);
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 1;
        int r = removable.size();
        int ans = 0;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(s, p, removable, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};