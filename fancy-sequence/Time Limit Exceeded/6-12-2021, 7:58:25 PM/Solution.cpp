// https://leetcode.com/problems/fancy-sequence

class Fancy {
public:
    typedef unsigned long long int ulli;
    vector<ulli> nums;
    ulli mult = 1;
    ulli add = 0;
    ulli M = 1e9 + 7;
    Fancy() {
        
    }
    
    void append(int val) {
        for (int i = 0; i < nums.size(); ++i) nums[i] = getIndex(i);
        mult = 1;
        add = 0;
        nums.push_back(val);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;
        add = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size() || idx < 0) return -1;
        return (nums[idx] * mult % M + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */