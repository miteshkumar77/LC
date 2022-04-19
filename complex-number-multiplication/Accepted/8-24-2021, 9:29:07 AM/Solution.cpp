// https://leetcode.com/problems/complex-number-multiplication

class Solution {
public:
    array<int, 2> get_components(string const& num) {
        if (num.find('+') == string::npos) {
            if (num.back() == 'i') {
                //return {0, stoi(num.substr(0, num.length() - 1))};
                return {0,0};
            } else {
                //return {stoi(num), 0};
                return {0,0};
            }
        } else {
            return {stoi(num.substr(0, num.find('+'))), stoi(num.substr(num.find('+') + 1, num.find('i') - num.find('+') - 1))};
        }
    }
    
    string complexNumberMultiply(string num1, string num2) {
        
        auto [r1, i1] = get_components(num1);
        auto [r2, i2] = get_components(num2);
        // cout << r1 << '+' << i1 << "i" << "   " << r2 << '+' << i2 << "i" << endl;
        /*
            (r1 + i1 * i) * (r2 + i2 * i) = (r1 * r2 - i1 * i2 + (r1 * i2 + r2 * i1) * i);
        */
        return to_string(r1 * r2 - i1 * i2) + "+" + to_string(r1 * i2 + r2 * i1) + "i";
    }
};