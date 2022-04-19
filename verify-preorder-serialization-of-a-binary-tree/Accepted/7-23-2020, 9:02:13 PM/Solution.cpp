// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 1 && preorder == "#") {
            return true; 
        }
        stack<int> pre; 
        int i = 0;
        preorder += ','; 
        string num;
        int numroots = 0; 
        while(i < preorder.size()) {
            
            num = preorder.substr(i, preorder.find(',', i) - i);
            if (num == "#") {
                if (pre.empty()) {
                    return false; 
                }
                
                int tmp = pre.top(); pre.pop();  
                while(!pre.empty() && pre.top() != tmp) {
                    tmp = pre.top(); pre.pop(); 
                }
            } else {
                if (pre.empty()) {
                    ++numroots; 
                    if (numroots > 1) {
                        return false; 
                    }
                }
                pre.push(i); 
                pre.push(i);
            }
            i = preorder.find(',', i) + 1;

        }
        
        
        return pre.empty(); 
    }
};