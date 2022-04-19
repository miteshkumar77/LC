// https://leetcode.com/problems/super-palindromes

class Solution {
public:
    typedef double bi;
    typedef unsigned long long int ulli;
    int ans;
    bool isPal(const string& s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    bool isOverflow(string& s, ulli mx) {
        std::string m = to_string(mx);
        return (m.length() < s.length() || (m.length() == s.length() && m < s));
    }
    
    void pals(string& box, ulli sql, ulli sqr) {
        if (box.length() > 5) return;
        string m1 = box;
        string m2 = box;
        reverse(box.begin(), box.end());
        m1 += box;
        m2 += (box.length() < 2) ? "" : box.substr(1, box.length() - 1);
        reverse(box.begin(), box.end()); 
        
        if (m1.length() != 0 && !isOverflow(m1, sqr)) {
            //cout << m1 << endl;
            ulli n1 = stoll(m1);
            if (n1 >= sql && isPal(to_string(n1 * n1))) {
                ++ans;
            }
        }
        if (m2.length() != 0 && !isOverflow(m2, sqr)) {
            //cout << m2 << endl;
            ulli n2 = stoll(m2);
            if (n2 >= sql && isPal(to_string(n2 * n2))) {
                ++ans;
            }
        }
        if (isOverflow(m1, sqr) && isOverflow(m2, sqr)) return;
        
        
        
        char start = box.length() == 0 ? '1' : '0';
        for (char c = (box.length() == 0) + '0'; c <= '9'; ++c) {
            box.push_back(c);
            pals(box, sql, sqr);
            box.pop_back();
        }
    }

    int superpalindromesInRange(string left, string right) {
        
        long long l = sqrt(stoll(left));
        long long r = sqrt(stoll(right));
        ans = 0;
        string bx;
        pals(bx, l, r);
        return ans;
    }
};

















