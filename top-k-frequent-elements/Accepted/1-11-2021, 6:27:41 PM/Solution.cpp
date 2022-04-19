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
        quickSelect(0, ct.size() - 1, sorter, ct.size() - k);
        // cout << "done selectnig" << endl;
        // for (auto p : sorter) cout << p[0] << ' ' << p[1] << endl;
        
        vector<int> ans; ans.reserve(k);
        
        for (int i = ct.size() - k; i < ct.size(); ++i) {
            ans.push_back(sorter[i][1]);
        }
        return ans;
        
    }
    
    void quickSelect(int l, int r, vector<array<int, 2>>& sorter, int k) {
        // cout << l << ' ' << r << ' ' << k << endl;
        // cout << "BEFORE: ";
        // for (auto p : sorter) {
        //     cout << p[0] << ' ';
        // }cout << endl;
        if (l > r) return;
        int pivoti = rand() % (r - l + 1) + l;
        swap(sorter[pivoti], sorter[r]);
        auto pivot = sorter[r];
        // cout << "PIVOT: " << pivot[0] << ' ' << pivot[1] << endl;
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (sorter[j][0] < pivot[0]) {
                swap(sorter[++i], sorter[j]);
            }
        }
        // cout << "AFTER: ";
        swap(sorter[++i], sorter[r]);
        // for (auto p : sorter) {
        //     cout << p[0] << ' ';
        // }
        
        // cout << endl << i << endl;
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