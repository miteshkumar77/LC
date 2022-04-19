// https://leetcode.com/problems/random-pick-with-blacklist

class Solution {
public:
    Solution(int n, vector<int>& blacklist) : h(n-1) {
        for (int i : blacklist) {
            idx_mp[h] = i;
            idx_mp[i] = h;
            h--;
        }
    }
    
    int pick() {
        int idx = rand() % (h+1);   
        return idx_mp.count(idx) ? idx_mp[idx] : idx;
    }
private:
    int h;
    unordered_map<int,int> idx_mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */