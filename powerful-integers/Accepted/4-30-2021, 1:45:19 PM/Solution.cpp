// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
    /*
    a >= a^i + b^j
    log(a/(a^i))
    ------------
       log(y)

    */   
        unordered_set<int> st;
        for (int xt = 1; bound >= xt; xt *= x) {
            for (int yt = 1; (bound - xt) >= yt; yt *= y) {
                st.insert(xt + yt);
                if (y == 1) break;
            }
            if (x == 1) break;
        }       
        
        return vector<int>(st.begin(), st.end());    
    }
};