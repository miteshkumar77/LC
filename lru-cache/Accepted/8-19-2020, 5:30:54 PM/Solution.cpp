// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity; 
    }
    
    int get(int key) {
        auto it = mp.find(key); 
        if (it == mp.end()) {
            return -1; 
        }
        
        int ret = (it -> second).second; 
        lst.erase((it -> second).first); 
        lst.push_front(it -> first);
        (it -> second).first = lst.begin(); 
        return ret; 
    }
    
    void put(int key, int value) {
        auto it = mp.find(key); 
        if (it != mp.end()) {
            (it -> second).second = value; 
            get(key); 
            return; 
        } else {
            lst.push_front(key); 
            mp[key] = make_pair(lst.begin(), value); 
        }
        
        if (lst.size() > cap) {
            int eject = lst.back(); 
            lst.pop_back(); 
            mp.erase(eject); 
        }
    }
private: 
    
    unordered_map<int, pair<list<int>::iterator, int>> mp; 
    list<int> lst; 
    int cap; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */