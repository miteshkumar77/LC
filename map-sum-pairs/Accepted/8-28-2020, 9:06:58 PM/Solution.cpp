// https://leetcode.com/problems/map-sum-pairs

class MapSum {
    
struct TN {
    
    TN() {
        isEnd = false; 
        sum = 0; 
        fill(letters.begin(), letters.end(), nullptr); 
    }
    
    array<TN*, 26> letters; 
    bool isEnd; 
    int sum; 
    
};
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        head = new TN(); 
    }
    
    void insert(string key, int val) {
        insertW(head, key, val, 0); 
    }
    
    int sum(string prefix) {
        return query(head, prefix); 
    }
    
    ~MapSum() {
        deleteNode(head); 
    }
    
private:
    
    void deleteNode(TN* r) {
        if (!r) {
            return; 
        }
        for (int i = 0; i < 26; ++i) {
            deleteNode(r -> letters[i]);
        }
        delete r; 
    }
    TN* head; 
    
    int insertW(TN* root, string& key, int val, int i) {
        if (i == key.length()) {
            if (!root -> isEnd) {    
                root -> sum += val; 
                root -> isEnd = true; 
                return val; 
            } else {
                int dif = val - root -> sum; 
                root -> sum = val; 
                return dif; 
            }
        }
        if (!(root -> letters)[key[i] - 'a']) {
            (root -> letters)[key[i] - 'a'] = new TN(); 
        }
        int ret = insertW((root -> letters)[key[i] - 'a'], key, val, i + 1); 
        root -> sum += ret; 
        return ret; 
    }
    
    int query(TN* root, string& key) {
        for (char c : key) {
            if (!(root -> letters)[c - 'a']) {
                return 0; 
            }
            root = (root -> letters)[c - 'a']; 
        }
        return root -> sum; 
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */