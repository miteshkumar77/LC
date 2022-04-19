// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, set<int>::iterator> imap; 
        set<int> vset; 
        for (int i = 0; i < nums.size(); ++i) {
            if (imap.find(i - k - 1) != imap.end()) {
                vset.erase(imap[i - k - 1]); 
                imap.erase(i - k - 1); 
            }
            
            // for (auto it = vset.begin(); it != vset.end(); ++it) {
            //     cout << (*it) << ' '; 
            // }cout << endl; 
            auto lb = vset.lower_bound(nums[i]); 
            vector<set<int>::iterator> vec{lb}; 
            if (lb != vset.begin()) {
                vec.push_back(prev(lb)); 
            }
            for (auto it : vec) {
                
                if (it != vset.end() && abs(nums[i] - (*it)) <= t) {
                    return true; 
                }
            }
            imap[i] = vset.insert(nums[i]).first; 
        }
        return false; 
    }
};