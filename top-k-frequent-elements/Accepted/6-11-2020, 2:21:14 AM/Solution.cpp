// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs; 
        for (int i = 0; i < nums.size(); ++i) {
            freqs.insert(make_pair(nums[i], 0)); 
            ++freqs[nums[i]]; 
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq; 
        for (pair<int, int> f : freqs) {
            pq.push(make_pair(f.second, f.first)); 
            if (pq.size() > k) {
                pq.pop(); 
            }
        }
        vector<int> ans; 
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second); 
            pq.pop(); 
        }
        return ans; 
    }
};