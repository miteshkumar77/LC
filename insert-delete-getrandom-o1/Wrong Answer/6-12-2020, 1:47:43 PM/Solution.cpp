// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    
    
private: 
    vector<int> rset; 
    unordered_map<int, int> qset; 
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        rset = vector<int>(); 
        qset = unordered_map<int, int>(); 
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (qset.find(val) != qset.end()) {
            return false; 
        }
        
        rset.push_back(val); 
        qset.insert(make_pair(val, rset.size() - 1)); 
        return true; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = qset.find(val); 
        if (it == qset.end()) {
            return false; 
        }
        qset[rset.back()] = it -> second; 
        swap(rset[rset.size() - 1], it -> second); 
        rset.pop_back(); 
        qset.erase(it); 
        return true; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return rset[rand() % rset.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */