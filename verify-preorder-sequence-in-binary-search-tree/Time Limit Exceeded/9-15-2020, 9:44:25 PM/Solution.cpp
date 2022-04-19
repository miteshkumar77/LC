// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        function<bool(int,int,int,int)> verify = [&](int L, int R, int mmin, int mmax) -> bool {
            // cout << L << ' ' << R << ' ' << mmin << ' ' << mmax << endl; 
            if (L > R) {
                return true; 
            }
            
            int mk = R + 1; 
            for (int i = L + 1; i <= R; ++i) {
                if (preorder[i] > preorder[L]) {
                    mk = i; 
                    break;
                }
            }
            
            // cout << mk << endl; 
            for (int i = L; i <= R; ++i) {
                // cout << preorder[i] << ' ' << mmin << ' ' << mmax << endl; 
                if (preorder[i] < mmin || preorder[i] > mmax) {
                    
                    return false; 
                }
            }
            
            return verify(L + 1, mk - 1, mmin, min(mmax, preorder[L])) &&
                verify(mk, R, max(mmin, preorder[L]), mmax); 
        };
        return verify(0, preorder.size() - 1, INT_MIN, INT_MAX); 
    }
};