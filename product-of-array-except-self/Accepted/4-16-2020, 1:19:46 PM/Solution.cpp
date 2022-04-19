// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int num_zeros = 0; 
        
        vector<int> res = vector<int>(nums.size()); 
        int running_prod = 1;  
        
        for (int i = 0; i < res.size(); ++i) {
            res[i] = running_prod; 
            running_prod *= nums[i];
        }
        
        running_prod = 1; 
        
        for (int j = res.size() - 1; j >= 0; --j) {
            res[j] *= running_prod; 
            running_prod *= nums[j]; 
        }
        
        return res; 
//         int total_product = 1; 
//         for (int n : nums) {
//             if (n == 0) {
//                 ++num_zeros;
                
//             } else {
//                 total_product *= n; 
//             }
//         }
        
//         vector<int> res = vector<int>(nums.size(), 0); 
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] != 0) {
//                 if (num_zeros == 0) {
//                     res[i] = total_product/nums[i];
//                 } 
//             } else {
//                 if (num_zeros == 1) {
//                     res[i] = total_product;
//                 }
//             }
//         }
        
//         return res; 
    }
};