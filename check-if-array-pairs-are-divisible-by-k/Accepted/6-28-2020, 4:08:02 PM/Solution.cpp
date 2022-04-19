// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> hm(k, 0); 
        int sz = 0; 
        for (int i = 0; i < arr.size(); ++i) {
            int mod = (arr[i] < 0)?((k + arr[i] % k) % k):(arr[i] % k); 
            int rem = (k - mod) % k; 
            if (hm[rem] > 0) {
                --hm[rem]; 
                --sz; 
            } else {
                hm[mod]++; 
                ++sz; 
            }
        }
        return sz == 0; 
    }
};