// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int i = 0;
        preorder += ','; 
        string num;
        int t = 1; 
        int numroots = 0; 
        while(i < preorder.size()) {
            
            num = preorder.substr(i, preorder.find(',', i) - i);
            if (num == "#") --t; 
            else (t += 1);
            if (t < 0) return false; 
            if (t == 0) ++numroots; 
            if (numroots > 1) return false; 
            i = preorder.find(',', i) + 1;
        }
        return t == 0; 
        
    }
};