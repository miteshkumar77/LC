// https://leetcode.com/problems/sliding-window-median

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        ans.reserve(nums.size() - k + 1);
        vector<int> window; 
        window.reserve(k); 
        for (int i = 0; i < k; ++i) {
            window.push_back(nums[i]); 
        }
        sort(window.begin(), window.end()); 
        ans.push_back(med(window)); 
        for (int i = k; i < nums.size(); ++i) {
            insertI(nums[i], window); 
            eraseI(nums[i - k], window); 
            ans.push_back(med(window)); 
        }
        return ans; 
        
    }
    
    
    double med(vector<int>& window) {
        int n = window.size(); 
        if (n % 2 == 0) {
            return ((double)(window[n/2]) + window[n/2 - 1])/2; 
        } else {
            return window[n/2]; 
        }
    }
    
    void insertI(int val, vector<int>& window) {
        window.insert(upper_bound(window.begin(), window.end(), val), val); 
    }
    void eraseI(int val, vector<int>& window) {
        window.erase(lower_bound(window.begin(), window.end(), val)); 
    }
    
    
    
};