// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        array<vector<char>, 10> lmap {
            vector<char>{},
            vector<char>{},
            vector<char>{'a', 'b', 'c'},
            vector<char>{'d', 'e', 'f'},
            vector<char>{'g', 'h', 'i'},
            vector<char>{'j', 'k', 'l'},
            vector<char>{'m', 'n', 'o'},
            vector<char>{'p', 'q', 'r', 's'},
            vector<char>{'t', 'u', 'v'},
            vector<char>{'w', 'x', 'y', 'z'}
        }; 
        
        list<char> box; 
        vector<string> ans; ans.reserve((int)pow(3, digits.size() + 1));
        generator(ans, lmap, box, digits, 0); 
        return ans; 
        
    }
    
    
    void generator(vector<string>& ans, array<vector<char>, 10>& lmap, list<char>& box, string& digits, int i) {
        if (i == digits.size()) {
            string s = "";
            for (auto it : box) {
                s += it;
            }
            if (s.length()) {
                ans.push_back(s); 
            }
            return; 
        }
        
        for (char c : lmap[digits[i] - '0']) {
            box.push_back(c); 
            generator(ans, lmap, box, digits, i + 1); 
            box.pop_back(); 
        }
    }
};