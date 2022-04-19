// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> js = unordered_set<char>(); 
        
        for (char c : J) {
            js.insert(c); 
        }
        int ans = 0; 
        for (char c : S) {
            if (js.find(c) != js.end()) {
                ++ans; 
            }
        }
        
        return ans; 
    }
};