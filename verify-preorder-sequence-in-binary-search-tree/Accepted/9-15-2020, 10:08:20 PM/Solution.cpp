// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        stack<int> mins; 
        stack<int> stk; 
        mins.push(INT_MIN); 
        stk.push(INT_MAX); 
        int i = 0; 
        while(i < preorder.size()) {
            int n = preorder[i]; 
            if (n < mins.top()) {
                return false; 
            }
            
            if (n < stk.top()) {
                stk.push(n); 
                mins.push(mins.top()); 
                ++i; 
            } else {
                mins.pop(); 
                mins.top() = max(mins.top(), stk.top()); 
                stk.pop(); 
            }
        }
        return true; 
    }
};