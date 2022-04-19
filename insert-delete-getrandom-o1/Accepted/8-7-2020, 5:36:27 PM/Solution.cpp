// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (rmap.find(val) == rmap.end()) {
            rmap.insert(make_pair(val, rset.size())); 
            rset.push_back(val); 
            return true; 
        }
        return false; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ans = false; 
        auto it = rmap.find(val); 
        if (it != rmap.end()) {
            ans = true; 
            rmap[rset.back()] = it -> second; 
            rset[it -> second] = rset.back(); 
            rset.pop_back(); 
            rmap.erase(val); 
        }
        return ans; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return rset[rand() % rset.size()]; 
    }
    
private: 
    unordered_map<int, int> rmap; 
    vector<int> rset; 
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */