// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int> >(); 
        }
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 
        vector<vector<int> > ans; 
        int prev = nums[0] + 1; 
        for (int i = 0; i < nums.size(); ++i) {
            if (prev != nums[i]) {
                cout << nums[i] << ' '; 
                prev = nums[i]; 
                int low = i + 1; 
                int high = n - 1; 
                while(low < high) {
                    
                    if (nums[low] + nums[high] < -nums[i]) {
                        ++low;
                    } else if (nums[low] + nums[high] > -nums[i]) {
                        --high; 
                    } else {
                        if (low == i + 1 || nums[low] != nums[low - 1] && 
                            high == n - 1 || nums[high] != nums[high + 1]) {
                            ans.push_back(vector<int>{nums[low], nums[high], nums[i]});
                        }
                        ++low;
                        --high; 
                    }
                }
            }
               
        }
        return ans; 
        
        
        
        
    }
};