// https://leetcode.com/problems/create-sorted-array-through-instructions

#define MAXN 100000
#define MAXS 400040
class Solution {
private:
    int M = 1e9 + 7;
    int tree[MAXS];
    
    void buildTree() {
        memset(tree, 0, sizeof(int) * MAXS);
    }
    
    int query(int l, int r) {
        int ret = queryHelper(l, r, 0, MAXN - 1, 0);
        return ret;
    }
    
    void incr(int idx) {
        incrHelper(idx , 0, MAXN - 1, 0);
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
        int ans = 0;
        buildTree();
        for (int i = 0; i < instructions.size(); ++i) {
            ans = (ans + min(query(0, instructions[i] - 1), query(instructions[i] + 1, MAXN - 1))) % M;
            incr(instructions[i]);
        }
        return ans;
    }
};