class Solution {
public:
    inline bool pow2(int a) {
        if (a == 0) return false;
        int pow = 1;
        for (int i = 0; i < 30; ++i, pow <<= 1) {
            if ((pow & a) == a) {
                return true;
            }
        }
        return false;
    }
    
    bool check_perm(int a, unordered_map<int,int>& ct, int digs, long long pow) {
        if (digs == 0) {
            if (pow2(a)) cout << a << endl;
            return pow2(a);
        }
        if (ct.count(0) && ct[0] && digs == (ct[0] + 1)) {
            --ct[0];
            bool ans = check_perm(a, ct, digs-1, pow * 10);
            ++ct[0];
            return ans;
        } else {
            for (auto const & [dig, num] : ct) {
                if (!num) continue;
                --ct[dig];
                bool ans = check_perm(a + pow * dig, ct, digs-1, pow * 10);
                ++ct[dig];
                if (ans) return true;
            }
            return false;
        }
    }
    
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> ct;
        int digs{0};
        while(n) {
            ++ct[n%10];
            n /= 10;
            ++digs;
        }
        return check_perm(0, ct, digs, 1);
    }
};