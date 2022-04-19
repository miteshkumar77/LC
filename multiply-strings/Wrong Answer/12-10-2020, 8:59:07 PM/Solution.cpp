// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    
    string add(string n1, string n2) {
        int i1 = n1.length() - 1;
        int i2 = n2.length() - 1;
        string ans; 
        int carry = 0;
        int sum;
        while(i1 >= 0 || i2 >= 0) {
            sum = carry;
            if (i1 >= 0) {
                sum += (int)(n1[i1--] - '0');
            }
            if (i2 >= 0) {
                sum += (int)(n2[i2--] - '0');
            }
            
            carry = sum/10;
            sum = sum % 10;
            ans += (char)(sum + '0');
        }
        if (carry > 0) {
            ans += (char)(carry + '0'); 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string multiply(string num1, string num2) {
        vector<string> levels;
        string zeros = "";
        for (int i1 = (int)num1.length() - 1; i1 >= 0; --i1) {
            levels.push_back(zeros);
            int carry = 0;
            int mult = 0;
            for (int i2 = (int)num2.length() - 1; i2 >= 0; --i2) {
                mult = carry;
                mult += ((int)(num2[i2] - '0')) * ((int)(num1[i1] - '0'));
                carry = mult/10;
                mult = mult % 10;
                levels.back() += (char)(mult + '0');
            }
            if (carry != 0) {
                levels.back() += (char)(carry + '0');
            }
            reverse(levels.back().begin(), levels.back().end());
            zeros += '0';
        }
        
        string ans = "0"; 
        for (string s : levels) {
            ans = add(ans, s);
        }
        
        return ans;
            
        
        // 123
        // 458
        // 
    }
};




