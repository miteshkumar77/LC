// https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret; 
        
        for (int i = 1; i <= n; ++i) {
            string s = ""; 
            if (i % 3 == 0) {
                s.append("Fizz"); 
            }
            
            if (i % 5 == 0) {
                s.append("Buzz"); 
            }
            
            if (s == "") {
                s.append(to_string(i)); 
            }
            ret.push_back(s); 
        }
        
        return ret; 
    }
};