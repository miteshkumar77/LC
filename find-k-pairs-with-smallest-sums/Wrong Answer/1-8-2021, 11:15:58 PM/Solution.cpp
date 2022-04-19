// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    int summ(const vector<int>& a) {
        return a[0] + a[1];
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        function<bool(const vector<int>&,const vector<int>&)> cmp = [&](const vector<int>& a, const vector<int>& b) -> bool {
            return summ(a) > summ(b); 
        };
        nums1.push_back(INT_MAX);
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxq(cmp);
        for (int i : nums1) {
            if (i == INT_MAX || (maxq.size() == k && summ(maxq.top()) <= i + nums2[0])) {
                while(!maxq.empty()) {
                    ans.push_back(maxq.top()); maxq.pop();
                }
                return ans;
            }
            
            for (int j = 0; j < nums2.size() && (maxq.size() < k || nums2[j] + i < summ(maxq.top())); ++j) {
                maxq.push({i, nums2[j]});
                if (maxq.size() > k) {
                    maxq.pop();
                }
            }
        }
        
        return ans;
        
    }
};