using ll = long long;
static const ll MIN_CONST{0};
class Solution {
public:
    
    class SegTree {
    private:
        vector<ll> tree;
        vector<ll> data;
        
        ll build(size_t node, size_t L, size_t R) {
            if (L == R) {
                tree[node] = data[L];
                return tree[node];
            } else {
                size_t mid = L + (R - L)/2;
                tree[node] = max(build(2 * node + 1, L, mid), build(2 * node + 2, mid+1, R));
                return tree[node];
            }
        }
        
        ll query(size_t node, size_t L, size_t R, size_t l, size_t r) {
            if (L >= l && R <= r) {
                return tree[node];
            } else if (L > r || R < l) {
                return MIN_CONST;
            } else {
                ll mid = L + (R - L)/2;
                return max(query(2 * node + 1, L, mid, l, r), query(2 * node + 2, mid+1, R, l, r));
            }
        }
        
        ll update(size_t node, size_t L, size_t R, size_t i, ll v) {
            if (L >= i && R <= i) {
                data[i] = v;
                tree[node] = v;
                return tree[node];
            } else if (R < i || L > i) {
                return tree[node];
            } else {
                size_t mid = L + (R - L)/2;
                tree[node] = max(update(2 * node + 1, L, mid, i, v), update(2 * node + 2, mid+1, R, i, v));
                return tree[node];
            }
        }
    public:
        ll query(size_t l, size_t r) {
            return query(0, 1, (ll)data.size() - 1, l, r);
        }
        
        ll update(size_t i, ll v) {
            return update(0, 1, (ll)data.size() - 1, i, v);
        }
        SegTree(vector<ll>&& A) : tree(5 * A.size(), MIN_CONST), data(std::move(A)) {}
        
    };
    
    int lengthOfLIS(vector<int>& nums, int k) {
        SegTree st(vector<ll> ((*max_element(nums.begin(), nums.end())) + 1, MIN_CONST));
        ll ans{1};
        
        for (int i = 0; i < nums.size(); ++i) {
            // std::cout << "query_begin ";
            ll dp = ((nums[i] == 1) ? 0 : st.query(max(1, nums[i] - k), nums[i] - 1));
            // std::cout << "query_end" << std::endl << "update_begin( " << nums[i] << ", " << dp+1 << ") ";
            st.update(nums[i], dp+1);
            // std::cout << "update_end" << std::endl;
            ans = max(ans, dp+1);
        }
        return ans;
        
    }
};