// https://leetcode.com/problems/lru-cache


class LRUCache {
public:
    
    unordered_map<int, int> store; 
    unordered_map<int, list<unordered_map<int, int>::iterator>::iterator> q_map; 
    list<unordered_map<int, int>::iterator> q; 
    int cap; 
    
    LRUCache(int capacity) {
        cap = capacity; 
        store = unordered_map<int, int>(); 
        q_map = unordered_map<int, list<unordered_map<int, int>::iterator>::iterator>(); 
        q = list<unordered_map<int, int>::iterator>(); 
    }
    
    int get(int key) {
        unordered_map<int, int>::iterator res = store.find(key); 
        if (res == store.end()) {
            return -1; 
        }
        
        unordered_map<int, list<unordered_map<int, int>::iterator>::iterator>::iterator res_loc = q_map.find(key); 
        q.splice(q.end(), q, res_loc -> second);
        return res -> second; 
    }
    
    void put(int key, int value) {
        
        if (store.find(key) != store.end()) {
            store[key] = value; 
            get(key); 
        } else {
            if (cap == q.size()) {
                unordered_map<int, int>::iterator to_eject = q.front(); 
                q_map.erase(to_eject -> first); 
                store.erase(to_eject -> first); 
                q.pop_front(); 
            }
         
            unordered_map<int, int>::iterator new_iter = (store.insert(pair<int, int>(key, value))).first;
            q.push_back(new_iter); 
            q_map.insert(pair<int, list<unordered_map<int, int>::iterator>::iterator>(key, (--q.end())));  

        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */