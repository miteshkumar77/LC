// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ct;
        for (int i : nums) ++ct[i];
        vector<array<int, 2>> sorter; sorter.reserve(ct.size()); 
        for (auto p : ct) {
            sorter.push_back({p.second, p.first});
        }
        // quickSelect(0, ct.size() - 1, sorter, ct.size() - k);
        nth_element(sorter.begin(), sorter.end(), sorter.begin() + k, 
                    [](const array<int, 2>& a, const array<int, 2>& b) -> bool {
                        return a[0] < b[0]; 
                    });
        
        vector<int> ans; ans.reserve(k);
        
        for (int i = ct.size() - k; i < ct.size(); ++i) {
            ans.push_back(sorter[i][1]);
        }
        return ans;
        
    }
    
    void quickSelect(int l, int r, vector<array<int, 2>>& sorter, int k) {

        if (l > r) return;
        int pivoti = rand() % (r - l + 1) + l;
        swap(sorter[pivoti], sorter[r]);
        auto pivot = sorter[r];

        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (sorter[j][0] < pivot[0]) {
                swap(sorter[++i], sorter[j]);
            }
        }
        swap(sorter[++i], sorter[r]);

        if (i == k + l - 1) {
            return;
        }
        
        if (i > k + l - 1) {
            quickSelect(l, i - 1, sorter, k);
        } else {
            quickSelect(i + 1, r, sorter, k - (i - l + 1)); 
        }

    };
};