// https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans; ans.reserve(n); 
        for (int i = 1; i <= n; ++i) {
            string t = ""; 
            if (i % 3 == 0) {
                t += "Fizz"; 
            }
            if (i % 5 == 0) {
                t += "Buzz"; 
            }
            if (t.length() == 0) {
                t += to_string(i); 
            }
            ans.push_back(t); 
        }
        return ans; 
    }
};