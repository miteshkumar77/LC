// https://leetcode.com/problems/expression-add-operators

class Solution {
public:
    
    typedef signed long long int slli;
    array<string, 3> ops{"+", "-", "*"}; 
    slli eval(string exp) {
        vector<string> stk;
        bool mult = false;
        for (char c : exp) {
            if (c >= '0' && c <= '9') {
                slli curr_num = c - '0'; 
                if (mult) {
                    stk.back() = to_string(stoll(stk.back()) * curr_num); 
                } else {
                    if (stk.size() != 0 && stk.back() != "+" && stk.back() != "-") {
                        stk.back() += to_string(curr_num); 
                    } else {
                        stk.push_back(to_string(curr_num)); 
                    }
                }
                mult = false;
            } else {
                if (c == '*') {
                    mult = true;
                } else {
                    stk.push_back(c == '-'?"-":"+"); 
                }
            }
        }
        
        bool add = true;
        slli result = 0;
        for (int i = 0; i < stk.size(); i += 2) {
            if (add) {
                result += stoll(stk[i]); 
            } else {
                result -= stoll(stk[i]); 
            }
            if (i != stk.size() - 1) {
                add = stk[i+1] == "+";
            }
        }
        return result;
    }
    
    void bt(string box, vector<string>& ans, const string& nums, slli target, slli i) {
        if (i == nums.size()) {
            if (eval(box) == target) {
                ans.push_back(box); 
            }
            return;
        }
        
        for (string op : ops) {
            bt(box + op + to_string(nums[i] - '0'), ans, nums, target, i + 1); 
        }
        bt(box + to_string(nums[i] - '0'), ans, nums, target, i + 1); 
    }
    
    vector<string> addOperators(string num, slli target) {
        string box;
        box.push_back(num[0]);
        
        vector<string> ans;
        bt(box, ans, num, target, 1); 
        return ans;
    }
};