// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    
    vector<vector<char> > mapping{
        vector<char>{},
        vector<char>{},
        vector<char>{'a','b','c'},
        vector<char>{'d','e','f'},
        vector<char>{'g','h','i'},
        vector<char>{'j','k','l'},
        vector<char>{'m','n','o'},
        vector<char>{'p','q','r','s'},
        vector<char>{'t','u','v'},
        vector<char>{'w','x','y','z'},
        
    }; 
    vector<string> letterCombinations(string digits) {
        string digs = digits; 
        string elem = ""; 
        vector<string> res; 
        if (digits == "") {
            return res; 
        }
        generator(digs, elem, res);
        return res; 
    }
    
    void generator(string& digits, string& elem, vector<string>& res) {
        if (elem.length() == digits.length()) {
            res.push_back(elem); 
            return; 
        }
        
        vector<char> int_map = mapping[digits[elem.size()] - '0']; 
        for (int i = 0; i < int_map.size(); ++i) {
            elem += int_map[i]; 
            generator(digits, elem, res); 
            elem.pop_back(); 
        }
    }
};