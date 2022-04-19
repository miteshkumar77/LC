// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    
    
    int getIdx(char c) { 
        return (c > 96)?(c % 32 + 25):(c % 32 - 1); 
    }
    int numJewelsInStones(string J, string S) {
        bool* js = new bool[42]{false};
        for (char c : J) {
            js[getIdx(c)] = true; 
        }
        int ans = 0; 
        for (char c : S) {
            if (js[getIdx(c)]) 
                ++ans; 
        }
        
        delete[] js; 
        return ans; 
    }
};