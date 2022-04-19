// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        function<bool(int,int)> verify = [&](int L, int R) -> bool {
            if (L >= R) {
                return true; 
            }
            int mk = R + 1; 
            for (int i = L + 1; i <= R; ++i) {
                if (preorder[i] > preorder[L]) {
                    mk = i; 
                }
                
                if (preorder[i] < preorder[L] && i > mk) {
                    return false; 
                }
            }
            
            return verify(L + 1, mk - 1) && verify(mk, R); 
        };
        
        return verify(0, preorder.size() - 1); 
    }
};