class Solution {
public:
    using ll = long long;
    long long appealSum(string s) {
        ll ans{0};
        for (int i = 1; i <= 26; ++i) {
            ans += appealSum(s, i);
        }
        return ans;
    }
    
    long long appealSum(string const& s, int ct) {
        array<int, 26> sct{0};
        array<int, 26> ect{0};
        int s_u{0};
        int e_u{0};
        
        int sj{0};
        int ej{0};
        ll ans{0};
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if ((sct[s[i]-'a']++) == 0) {
                ++s_u;
            }
            if ((ect[s[i]-'a']++) == 0) {
                ++e_u;
            }
            
            while(e_u >= ct) {
                if ((--ect[s[ej++]-'a']) == 0) {
                    --e_u;
                }
            }
            
            while(s_u > ct) {
                if ((--sct[s[sj++]-'a']) == 0) {
                    --s_u;
                }
            }
            ans += ((ll)(ct)) * ((ll)(ej - sj));
        }
        return ans;
        
    }
};