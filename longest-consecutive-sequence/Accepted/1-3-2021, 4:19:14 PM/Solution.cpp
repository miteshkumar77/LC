// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); 
        int ans = 0;
        
        while(!st.empty()) {
            int num = *st.begin();
            int tmp = 1;
            int l = num;
            int r = num;
            st.erase(num);
            while(st.find(l - 1) != st.end()) {
                ++tmp;
                st.erase(l--); 
            }
            while(st.find(r + 1) != st.end()) {
                ++tmp;
                st.erase(r++);
            }
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};