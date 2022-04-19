// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    
    // bool mf (const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second > b.second; 
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs; 
        for (int i = 0; i < nums.size(); ++i) {
            freqs.insert(make_pair(nums[i], 0)); 
            ++freqs[nums[i]]; 
        }
        vector<pair<int, int> > kth (freqs.begin(), freqs.end()); 
        nth_element(kth.begin(), kth.begin() + k, kth.end(), [] (const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second > b.second; 
        }); 
        
        
        vector<int> ans; ans.reserve(k); 
        for (int i = 0; i < k; ++i) {
            ans.push_back(kth[i].first); 
        }
        return ans; 
        
    }
};