// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int j = 0;
        int run = 0;
        
        for (int i = 0; i <= chars.size(); ++i) {
            if (i == chars.size() || chars[i] != chars[j]) {
                if (run != 1) {
                    for (char c : to_string(run)) {
                        chars[++j] = c;
                    }
                }
                if (i != chars.size()) {
                    chars[++j] = chars[i];
                }
                run = 0;
            }
            ++run;
        }
               
        return j+1;
    }
};