// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> trans = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
        unordered_set<string> convs;
        function<string(string&)> transform = [&](string& word) -> string {
            string res = "";
            for (char c : word) {
                res += trans[c - 'a']; 
            }
            return res;
        };
        
        for (string wd : words) {
            convs.insert(transform(wd));
        }
        return convs.size();
    }
};