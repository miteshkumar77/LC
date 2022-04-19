// https://leetcode.com/problems/longest-duplicate-substring

class Solution {
public:
    string longestDupSubstring(string S) {
        int L = 0; 
        int R = S.length() - 1;
        string ans = ""; 
        // cout << test(1, S).second << endl; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            pair<bool, string> r = test(mid, S); 
             
            if (r.first) {
                ans = r.second; 
                L = mid + 1; 
            } else {
                R = mid - 1; 
            }
        }
        return ans; 
    }
    
    pair<bool, string> test(int L, string& S) {
        // cout << L << endl; 
        unordered_set<string> us; 
        string s = ""; 
        for (int i = 0; i < L; ++i) {
            s += S[i]; 
        }
        us.insert(s); 
        for (int i = L; i < S.length(); ++i) {
            // cout << s << endl; 
           
            s += S[i]; 
            s = s.substr(1); 
            if (us.find(s) != us.end()) {
                return make_pair(true, s);  
            }
            us.insert(s); 
        }
        return make_pair(false, ""); 
    }
};