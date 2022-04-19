// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ct; 
        for (int i : arr) ++ct[i]; 
        vector<int> buckets(arr.size() + 1, 0); 
        for (auto p : ct) ++buckets[p.second]; 
        int ans = 0; 
        int lim = arr.size()/2; 
        if (arr.size() % 2 == 0) {
            lim -= 1; 
        }
        int sum = 0; 
        for (int i = buckets.size() - 1; i >= 0; --i) {
            if (buckets[i] > 0) {
                while(buckets[i] > 0) {
                    sum += i; 
                    --buckets[i]; 
                    ++ans; 
                    if (sum > lim) {
                        return ans; 
                    }
                }
            }
        }
        return ans; 
    }
};