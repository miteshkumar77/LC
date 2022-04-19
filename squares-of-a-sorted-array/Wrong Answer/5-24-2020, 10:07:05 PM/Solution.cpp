// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans; ans.reserve(A.size()); 
        int center = 0; 
        for (int i = 1; i < A.size(); ++i) {
            if (abs(A[i]) < abs(A[center])) {
                center = i; 
            } else {
                break;
            }
            
        }
        
        cout << center << endl; 
        int left_ptr = center - 1; 
        int right_ptr = center + 1; 
        ans.push_back(A[center] * A[center]); 
        while(left_ptr >= 0 && right_ptr < A.size()) {
            if (left_ptr >= 0 && (right_ptr >= A.size() || abs(A[left_ptr]) <= abs(A[right_ptr]))) {
                ans.push_back(A[left_ptr]*A[left_ptr--]);
            }
            
            if (right_ptr < A.size() && (left_ptr < 0 || abs(A[left_ptr]) >= abs(A[right_ptr]))) {
                ans.push_back(A[right_ptr]*A[right_ptr++]);
            }
        }
        
        return ans; 
    }
};