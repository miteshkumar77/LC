// https://leetcode.com/problems/create-sorted-array-through-instructions

class Solution {
private:
    int M = 1e9 + 7;
    vector<int> tree;
    int n;
    void buildTree(int n) {
        this->n = n;
        tree = vector<int>(3 * n, 0);
    }
    
    int query(int l, int r) {
        int ret = queryHelper(l, r, 0, n - 1, 0);
        return ret;
    }
    
    void incr(int idx) {
        incrHelper(idx , 0, n - 1, 0);
    }
    
    int queryHelper(int l, int r, int L, int R, int node) {
        if (L > R || L > r || R < l) {
            return 0;
        }
       
        if (L >= l && R <= r) {
            return tree[node];
        }
        int mid = L + (R - L)/2;
        return (queryHelper(l, r, L, mid, 2 * node + 1) +
                queryHelper(l, r, mid + 1, R, 2 * node + 2)) % M;
        
    }
    
    
    
    int incrHelper(int idx, int L, int R, int node) {
        if (L > R) return 0;
        
        if (R < idx || L > idx) return tree[node];
        if (L == R) {
            tree[node] = (1 + tree[node]) % M;
            return tree[node];
        }
        int mid = L + (R - L)/2;
        tree[node] = (incrHelper(idx, L, mid, 2 * node + 1) +
                      incrHelper(idx, mid + 1, R, 2 * node + 2)) % M;
        return tree[node];
    }
    
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> cpy(instructions.begin(), instructions.end());
        int n = instructions.size();
        vector<array<int, 2>> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = {instructions[i], i};
        }
        sort(indices.begin(), indices.end(), [](const array<int,2>& a, const array<int,2>& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);    
        });
        for (int i = 0; i < n; ++i) {
            instructions[indices[i][1]] = i;
        }
        unordered_map<int, int> ct;
        int ans = 0;
        int i;
        buildTree(n);
        for (int j = 0; j < n; ++j) {
            i = instructions[j];
            incr(i);
            int l = query(0, i - 1) - ct[cpy[j]]; 
            int r = query(i + 1, n - 1);
            ans = (ans + min(l, r)) % M;
            ++ct[cpy[j]];
        }
        return ans;
    }
};