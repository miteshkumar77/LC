// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> box;
        vector<int> ans;
        function<void(int)> bt = [&](int i) -> void {
            if (i == nums.size()) {
                if (box.size() > ans.size()) {
                    ans = box;
                }
                return;
            }
            
            bool ok = true;
            for (int x : box) {
                if (x % nums[i] != 0 && nums[i] % x != 0) {
                    // cout << nums[i] << endl;
                    // for (int x : box) cout << x << ' ';
                    // cout << endl;
                    
                    ok = false;
                    break;
                }
            }

            if (ok) {
                box.push_back(nums[i]);
                bt(i + 1);
                box.pop_back();
                bt(i + 1);
            } else {
                bt(i + 1);
            }
                
                
        };
        
        bt(0); 
        return ans;
    }
};