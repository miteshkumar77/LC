// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        fill(ht.begin(), ht.end(), false); 
    }
    
    void add(int key) {
        ht[key] = true; 
    }
    
    void remove(int key) {
        ht[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return ht[key]; 
    }
private:
    array<bool, 1000001> ht; 

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */