// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> seen; 
        for (int i = 0; i < arr.size(); ++i) {
            int mod = arr[i] % k; 
            int rem; 
            
            if (mod == 0) {
                rem = 0; 
            } else if (mod < 0) {
                mod = mod + k; 
                rem = abs(mod); 
            } else {
                rem = k - mod; 
            }
            
            if (seen.find(rem) != seen.end()) {
                seen[rem]--; 
                if (seen[rem] == 0) {
                    seen.erase(rem); 
                }
            } else {
                seen.insert(make_pair(mod, 1)); 
            }
        }
        return seen.size() == 0; 
    }
};