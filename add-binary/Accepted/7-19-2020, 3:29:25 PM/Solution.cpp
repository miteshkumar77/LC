// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int ap = 0;
        int bp = 0;
        int carry = 0;
        
        while(ap < a.length() || bp < b.length()) {
            int aval = ap < a.length() && a[a.length() - 1 - ap++] == '1';
            int bval = bp < b.length() && b[b.length() - 1 - bp++] == '1';
            sum.push_back((char)(aval ^ bval ^ carry + '0'));
            carry = (aval && bval) || (aval && carry) || (bval && carry);
        }
        if (carry) {
            sum.push_back((char)(carry + '0'));
        }
        reverse(sum.begin(), sum.end()); 
        return sum;
    }
};