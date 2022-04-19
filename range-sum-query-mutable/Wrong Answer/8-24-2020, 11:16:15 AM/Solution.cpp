// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    
    vector<int> st; 
    vector<int> data; 
    int size; 
    NumArray(vector<int>& nums) {
        data = nums; 
        size = nums.size(); 
        st = vector<int>(nums.size() * 4); 
        treeBuilder(0, size - 1, 0, nums); 
    }
    
    void update(int i, int val) {
        int diff = val - data[i]; 
        updateHelper(i, 0, size - 1, 0, diff); 
        data[i] = val; 
    }
    
    int sumRange(int i, int j) {
        return sumRangeHelper(0, size - 1, 0, i, j); 
    }
private:
    void updateHelper(int i, int L, int R, int root, int val) {
        if (root >= st.size()) {
            return; 
        }
        st[root] += val; 
        if (L == R) { 
            return ;
        }
        int mid = L + (R - L)/2; 
        if (L <= i <= mid) {
            updateHelper(i, L, mid, root * 2 + 1, val); 
        } else {
            updateHelper(i, mid + 1, R, root * 2 + 2, val); 
        }
        
    }
    int sumRangeHelper(int L, int R, int root, int i, int j) {
        if (root >= st.size()) {
            return 0; 
        }
        if (L == R) {
            return st[root]; 
        }
        
        int mid = L + (R - L)/2; 
        int ans = 0;
        
        if (L <= i <= R) {
            ans += sumRangeHelper(L, mid, root * 2 + 1, i , j); 
        }
        
        if (L <= j <= R) {
            ans += sumRangeHelper(mid + 1, R, root * 2 + 2, i , j); 
        }
        return ans; 
        
    }
    void treeBuilder(int L, int R, int root, vector<int>& nums) {
        
        if (root >= st.size()) {
            return; 
        }
        if (L == R) {
            st[root] = nums[L]; 
            return; 
        }
        
        int mid = L + (R - L)/2; 
        treeBuilder(L, mid, 2 * root + 1, nums); 
        treeBuilder(mid + 1, R, 2 * root + 2, nums); 
        
        st[root] = st[2 * root + 1] + st[2 * root + 2]; 
    }
    
};

// ["NumArray","sumRange","update","sumRange"]
// [[[1,3,5,7,2,6]],[0,2],[1,2],[0,2]]

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */