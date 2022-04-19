// https://leetcode.com/problems/combinations

class Solution {
public:
    vector<vector<int>> combine(int ni, int ki) {
        vector<vector<int>> prod; 
        
        vector<int> box; 
        
        function<void(int,int,int)> bt = [&](int n, int i, int k) -> void {
            
            if (k == 0) {
                prod.push_back(box);
                return;
            }
            
            if (k > n - i + 1) {
                return;
            }
            
            for (int j = i; j <= n; ++j) {
                box.push_back(j);
                bt(n, j + 1, k - 1);
                box.pop_back();
            }
        };
        
        bt(ni, 1, ki);
        return prod;
    }
};