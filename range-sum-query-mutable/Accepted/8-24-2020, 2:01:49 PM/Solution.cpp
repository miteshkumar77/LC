// https://leetcode.com/problems/range-sum-query-mutable


    class NumArray {


    public: 
        NumArray(vector<int>& nums) {
            n = nums.size(); 
            tree = vector<int>(4 * n); 
            build_tree(nums, 0, n - 1, 0); 
        }


        void update(int i, int val) {
            update_tree(0, n - 1, i, val, 0); 
        }

        int sumRange(int i, int j) {
            return query(0, n - 1, i, j, 0); 
        }

    private:


        int query(int L, int R, int bL, int bR, int root) {
            if (L > R) {
                return 0; 
            }

            if (L > bR || R < bL) {
                return 0; 
            }

            if (L >= bL && R <= bR) {
                return tree[root]; 
            }
            int mid = L + (R - L)/2; 
            return query(L, mid, bL, bR, 2 * root + 1) +
                query(mid + 1, R, bL, bR, 2 * root + 2); 
        }

        int build_tree(vector<int>& nums, int L, int R, int root) {
            if (L > R) {
                return 0; 
            }

            if (L == R) {
                tree[root] = nums[L]; 
                return tree[root]; 
            }

            int mid = L + (R - L)/2; 

            tree[root] = build_tree(nums, L, mid, 2 * root + 1) + 
                build_tree(nums, mid + 1, R, 2 * root + 2); 
            return tree[root]; 
        }


        int update_tree(int L, int R, int idx, int val, int root) {

            if (L > R) {
                return 0; 
            }
            if (L > idx || R < idx) {
                return tree[root]; 
            }
            if (L == R) {
                tree[root] = val; 
                return tree[root]; 
            }
            int mid = L + (R - L)/2; 
            tree[root] = update_tree(L, mid, idx, val, 2 * root + 1) + 
                    update_tree(mid + 1, R, idx, val, 2 * root + 2); 
            return tree[root]; 

        }

        vector<int> tree;  
        int n; 
    }; 

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */