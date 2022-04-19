// https://leetcode.com/problems/design-hashmap

class MyHashMap {
private:
    

    template <class K, class V>
class HashMap {
public: 
    HashMap(double occupancy_ratio = 0.7, int initial_size = 1000) : f(occupancy_ratio) {
        K def; 
        data = vector<tuple<bool,bool,K>>(initial_size, tuple<bool,bool,K>(false, false, def)); 
        values = vector<V>(initial_size);
        occupied = 0; 
        size = 0; 
    }
    
    
    bool insert(K key, V val) {
        rehash(); 
        int init_idx = search(key); 
        
        if (std::get<0>(data[init_idx]) && std::get<2>(data[init_idx]) == key) {
            return false; 
        }
        
        int insert_idx = searchInsert(key); 
        if (!std::get<1>(data[insert_idx])) {
            ++occupied; 
        }
        
        data[insert_idx] = make_tuple(true, true, key); 
        values[insert_idx] = val;
        ++size; 
        return true; 
    }
    
    pair<bool, V> getVal(K key) {
        int init_idx = search(key); 
        if (std::get<0>(data[init_idx]) && std::get<2>(data[init_idx]) == key) {
            return make_pair(true, values[init_idx]);
        }
        return make_pair(false, 0); 
    }


    void set(K key, V val) {
        rehash(); 
        int init_idx = search(key); 
        if (std::get<0>(data[init_idx]) && std::get<2>(data[init_idx]) == key) {
            values[init_idx] = val;
            return;
        }
        insert(key, val); 
    }

    bool contains(K key) {
        int init_idx = search(key); 
        
        if (std::get<0>(data[init_idx]) && std::get<2>(data[init_idx]) == key) {
            return true; 
        }
        return false; 
    }
    
    
    bool erase(K val) {
        int first_occ = search(val); 
        if (!std::get<1>(data[first_occ]) || !std::get<0>(data[first_occ])) {
            return false; 
        }
        
        if (std::get<2>(data[first_occ]) == val) {
            --size; 
            data[first_occ] = make_tuple(false, true, val); 
            return true; 
        }
        return false; 
    }
    
    
    
    

    
    
private: 
    
    
    int searchInsert(K val) {
        int hval = mhash(val); 
        int x = 0; 
        int idx = (hval % data.size() + P(x)) % data.size(); 
        
        while(std::get<0>(data[idx])) {
            ++x; 
            idx = (hval % data.size() + P(x)) % data.size(); 
        }
        return idx; 
    }
    
    int search(K val) {
        int hval = mhash(val); 
        int x = 0; 
        int idx = (hval % data.size() + P(x)) % data.size(); 
        while(std::get<1>(data[idx])) {
            if (std::get<0>(data[idx]) && std::get<2>(data[idx]) == val) {
                return idx; 
            }
            ++x; 
            idx = (hval % data.size() + P(x)) % data.size(); 
        }
        
        return idx; 
    }
    
    int P(int x) {
        return x; 
    }
    
    void rehash() {
        if (((double)occupied)/data.size() < f) {
            return; 
        }

        K def; 
        vector<tuple<bool,bool,K>> n_data(data.size() * 2, tuple<bool, bool, K>(false, false, def)); 
        vector<V> n_values(data.size() * 2);
        data.swap(n_data); 
        values.swap(n_values); 
        size = 0; 
        occupied = 0; 
        int i = 0; 
        for (auto [isOccupied, tomb, key] : n_data) {
            if (isOccupied) {
                insert(key, n_values[i]); 
            } 
            ++i;
        }
    }
    
    
    int mhash(const K& val) {
        
        return hash<K>{}(val);  
    }
    
    
    
    vector<tuple<bool,bool,K>> data;
    vector<V> values;  
    int size; 
    int occupied; 
    double f; 
    
};
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        m_hm.set(key, value); 
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        // cout << "get " << key << endl; 
        auto p = m_hm.getVal(key); 
        if (p.first) {
            return p.second;
        }
        return -1; 
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        // cout << "remove " << key << endl; 
        m_hm.erase(key); 
    }
    
private:
    HashMap<int,int> m_hm; 
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
