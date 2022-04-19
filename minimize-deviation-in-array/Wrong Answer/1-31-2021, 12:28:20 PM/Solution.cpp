// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        map<int,int> ct;
        for (int i : nums) ++ct[i];
        
        int current_diff;
        int minval;
        int maxval;
        
        for (int i = 0; i < n; ++i) {
            minval = ct.begin() -> first;
            maxval = prev(ct.end()) -> first;
            current_diff = maxval - minval;
            // for (auto p : ct) cout << p.first << ' ' << p.second << " | ";
            // cout << endl;
            if (minval % 2 == 1 && abs(maxval - minval * 2) < current_diff) {
                --(ct.begin() -> second);
                if (ct.begin() -> second == 0) {
                    ct.erase(minval); 
                }
                ++ct[minval * 2];
            } else if (maxval % 2 == 0 && abs(maxval/2 - minval) < current_diff) {
                --(prev(ct.end())->second); 
                if ((prev(ct.end())->second) == 0) {
                    ct.erase(maxval); 
                    ++ct[maxval/2];
                }
            } else {
                break;
            }
        }
        return current_diff;
        
    }
};