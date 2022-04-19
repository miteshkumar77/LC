// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    NumArray(vector<int>& nums) {
        tree = vector<int>(nums.size() * 4); 
        n = nums.size() - 1; 
        orig.swap(nums); 
        buildTree(orig, 0, n, 0); 
    }
    
    void update(int i, int val) {
        // cout << orig.size() << ' ' << i << endl; 
        int dif = val - orig[i]; 
        orig[i] = val; 
        // cout << "beginning update" << endl; 
        updateTree(0, n, 0, dif, i); 
        // cout << "updated" << endl; 
    }
    
    int sumRange(int i, int j) {
        int ans = queryTree(0, n, i, j, 0); 
        // cout << "query " << i << ", " << j << ": " << ans << endl; 
        return ans; 
    }
    
private: 
    
    
    
    int queryTree(int L, int R, int bL, int bR, int root) {
        // cout << bL << ' ' << bR << ' ' << L << ' ' << R << ' ' << root << endl; 
        if (L > R) {
            return 0; 
        }
        
        if (R < bL || L > bR) {
            return 0; 
        }
        
        if (L >= bL && R <= bR) {
            return tree[root]; 
        }
        
        int mid = L + (R - L)/2; 
        return queryTree(L, mid, bL, bR, 2 * root + 1) + 
            queryTree(mid + 1, R, bL, bR, 2 * root + 2); 
    }
    
    void updateTree(int L, int R, int root, int val, int idx) {
        // cout << L << ' ' << R << ' ' << root << endl; 
        if (L > R) {
            return; 
        }
        
        
        
        if (L > idx || R < idx) {
            return; 
        }
        
        
        
        tree[root] += val;
        if (L == R) {
            return; 
        }
        int mid = L + (R - L)/2; 
        updateTree(L, mid, 2 * root + 1, val, idx); 
        updateTree(mid + 1, R, 2 * root + 2, val, idx); 
    }
    
    int buildTree(vector<int>& nums, int L, int R, int root) {
        if (L > R) {
            return 0; 
        }
        
        if (L == R) {
            tree[root] = nums[L]; 
            return tree[root]; 
        }
        
        int mid = L + (R - L)/2; 
        
        tree[root] = buildTree(nums, L, mid, 2 * root + 1) + 
                    buildTree(nums, mid + 1, R, 2 * root + 2); 
        return tree[root]; 
        
    }
    vector<int> tree; 
    vector<int> orig; 
    int n; 
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */