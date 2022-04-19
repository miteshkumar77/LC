// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
            return b < a;
        });
        
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || nums.size() < 4) return false;
        
        int side_len = sum/4;
        
        array<int, 4> arr{0, 0, 0, 0};
        
        function<bool(int)> bt = [&](int i) -> bool {
            if (i >= nums.size()) {
                // return arr[0] == side_len && 
                //        arr[1] == side_len && 
                //        arr[2] == side_len && 
                //        arr[3] == side_len;
                
                return true;
            }

            for (int x = 0; x < 4; ++x) {
                if (arr[x] + nums[i] <= side_len) {
                    arr[x] += nums[i]; 
                    bool b = bt(i+1);
                    arr[x] -= nums[i];
                    if (b) {
                        return true;
                    }
                }
            }
            
            return false;
        };
        
        return bt(0);
        
    }
};