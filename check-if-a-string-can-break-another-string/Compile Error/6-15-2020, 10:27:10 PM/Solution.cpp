// https://leetcode.com/problems/check-if-a-string-can-break-another-string

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        array<int, 26> arr1{0}; 
        array<int, 26> arr2{0}; 
        
        for (int i = 0; i < s1.length(); ++i) {
            ++arr1[s1[i] - 'a'];
            ++arr2[s2[i] - 'a']; 
        }
        for (int i = 1; i < 26; ++i) {
            arr1[i] += arr1[i - 1]; 
            arr2[i] += arr2[i - 1]; 
        }
        
        for (int i = 0; i < 26; ++i) {
            if (arr1[i] < arr2[i]) {
                all_1_gt = false; 
            }
            
            if (arr2[i] < arr1[i]) {
                all_2_gt = false; 
            }
            if (!(all_1_gt || all_2_gt)) {
                return false; 
            }
        }
        return true; 
         
    }
    
    
    
};