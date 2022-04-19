// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    
    NumArray(vector<int>& nums) : nums(nums) {
        build(0, (int)nums.size() - 1, 0);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        update(index, 0, (int)nums.size() - 1, 0, diff);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, (int)nums.size() - 1, 0);
    }
    
private:
    int build(int l, int r, int node) {
        if (l == r) {
            tree[node] = nums[l];
            return nums[l];
        } 
        int mid = l + (r - l)/2;
        int sum = build(l, mid, node * 2 + 1) + build(mid + 1, r, node * 2 + 2);
        tree[node] = sum;
        return sum;
    }
    
    int query(const int L, const int R, int l, int r, int node) const {
        if (l >= L && r <= R) return tree.find(node)->second;
        if (r < l || l > r) return 0;
        //if (l == r) tree.find(node)->second;
        int mid = l + (r - l)/2;
        return query(L, R, l, mid, node * 2 + 1) + query(L, R, mid + 1, r, node * 2 + 2);
    }
    
    void update(const int idx, int l, int r, int node, const int diff) {
        if (l > idx || r < idx) return;
        tree[node] += diff;
        if (l == r) return;
        int mid = l + (r - l)/2;
        update(idx, l, mid, node * 2 + 1, diff);
        update(idx, mid+1, r, node * 2 + 2, diff);
    }
    
    unordered_map<int, int> tree;
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */