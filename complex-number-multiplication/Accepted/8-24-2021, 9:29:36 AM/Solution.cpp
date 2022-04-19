// https://leetcode.com/problems/complex-number-multiplication

class Solution {
public:
    array<int, 2> get_components(string const& num) {
        return {stoi(num.substr(0, num.find('+'))), stoi(num.substr(num.find('+') + 1, num.find('i') - num.find('+') - 1))};
    }
    
    string complexNumberMultiply(string num1, string num2) {
        
        auto [r1, i1] = get_components(num1);
        auto [r2, i2] = get_components(num2);
        return to_string(r1 * r2 - i1 * i2) + "+" + to_string(r1 * i2 + r2 * i1) + "i";
    }
};