// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        table = vector<int>(100, -1); 
        size = 0; 
        ratio = 0.7; 
    }
    
    void add(int key) {
        if (size / table.size() > ratio) {
            rehash(); 
        }
        
        int idx = (m_hash(key))%table.size(); 
        while(table[idx] != -1) {
            if (table[idx] == key) {
                return; 
            }
            ++idx; 
            idx = idx % table.size(); 
        }
        table[idx] = key; 
        ++size; 
    }
    
    void remove(int key) {
        int idx = (m_hash(key)) % table.size(); 
        while(table[idx] != key) {
            if (table[idx] == -1) {
                return; 
            }
            ++idx; 
            idx = idx % table.size(); 
        }
        --size; 
        table[idx] = -1; 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = (m_hash(key)) % table.size(); 
        while(table[idx] != key) {
            if (table[idx] == -1) {
                return false; 
            }
            ++idx; 
            idx = idx % table.size(); 
        }
        return true; 
    }
private:
    vector<int> table; 
    int size; 
    double ratio; 
    void rehash() {
        // cout << "hashing" << endl; 
        vector<int> tmp;
        tmp.swap(table); 
        table = vector<int>(tmp.size() * 2, -1); 
        // cout << "created table" << endl; 
        for (int key : tmp) {
            if (key != -1) {
                add(key); 
            }
        }
        // cout << "rehashed" << endl; 
    }
    
    int m_hash(int key) {
        return hash<int>{}(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */