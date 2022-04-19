// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers

class Solution {
public:
    typedef unsigned long long int lli; 
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<lli,int> n1;
        unordered_map<lli,int> n2; 
        for (int i : nums1) {
            ++n1[((lli)i) * i];
        }
        for (int i : nums2) {
            ++n2[((lli)i)*i]; 
            
        }
        int ans = 0; 
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = i + 1; j < nums1.size(); ++j) {
                if (n2.find((((lli)nums1[i]) * nums1[j])) != n2.end()) {
                    ans += n2[((lli)nums1[i]) * nums1[j]];  
                }
            }
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            for (int j = i + 1; j < nums2.size(); ++j) {
                if (n1.find((((lli)nums2[i]) * nums2[j])) != n1.end()) {
                    ans += n1[((lli)nums2[i]) * nums2[j]];
                }
            }
        }
        
        return ans; 
        
    }
};