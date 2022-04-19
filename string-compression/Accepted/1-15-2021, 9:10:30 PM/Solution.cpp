// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int j = 0;
        int run = 0;
        
        for (int i = 0; i < chars.size(); ++i) {
            if (chars[i] != chars[j]) {
                if (run != 1) {
                    for (char c : to_string(run)) {
                        chars[++j] = c;
                    }
                }
                chars[++j] = chars[i];
                run = 0;
            }
            ++run;
        }
        if (run != 1) {
            for (char c : to_string(run)) {
                chars[++j] = c;
            }
        }        
        return j+1;
    }
};