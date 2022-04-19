// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 1 && preorder == "#") {
            return true; 
        }
        stack<string> pre; 
        int i = 0;
        preorder += ','; 
        string num;
         
        while(i < preorder.size()) {
            
            num = preorder.substr(i, preorder.find(',', i) - i);
            if (num == "#") {
                if (pre.empty()) {
                    return false; 
                }
                
                string tmp = "#"; 
                while(!pre.empty() && pre.top() != tmp) {
                    tmp = pre.top(); pre.pop(); 
                }
            } else {
                pre.push(num); 
                pre.push(num);
            }
            i = preorder.find(',', i) + 1;

        }
        
        
        return pre.empty(); 
    }
};