// https://leetcode.com/problems/two-sum-iii-data-structure-design

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_set<int> seen;
        for (int i : nums) {
            if (seen.find(value - i) != seen.end()) {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
private:
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */