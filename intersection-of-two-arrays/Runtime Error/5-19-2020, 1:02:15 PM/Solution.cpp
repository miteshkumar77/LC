// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end()); 
        vector<int> res_set; 
        auto i1 = nums1.begin();
        auto i2 = nums2.begin(); 
        
        
        if (nums1.back() < nums2[0] || nums2.back() < nums1[0]) {
            return res_set; 
        }
        

        while(i1 != nums1.end() && i2 != nums2.end()) {
            if ((*i1) > (*i2)) {
                ++i2; 
            } else if ((*i2) > (*i1)) {
                ++i1; 
            } else {
                if (res_set.size() != 0 && (*i1) == res_set.back()) {
                    ++i1;
                    ++i2; 
                } else {
                    res_set.push_back(*i1); 
                }
            }
        }
        
        return res_set; 
        
    }
};