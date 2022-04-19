// https://leetcode.com/problems/map-sum-pairs

class MapSum {
private:
    struct TN {
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
        }
        array<TN*, 26> letters;    
        int sum{0};
        int contrib{0};
    };
    
    TN* root;
    
    int insert(TN* head, int idx, string const& key, int val) {
        if (idx == key.length()) {
            int orig = head->contrib;
            head->contrib = val;
            head->sum = head->sum - orig + val;
            return orig;
        } else {
            if (!(head->letters)[key[idx]-'a']) {
                (head->letters)[key[idx]-'a'] = new TN();
            }
            int orig = insert((head->letters)[key[idx]-'a'], idx+1, key, val);
            head->sum = head->sum - orig + val;
            return orig;
        }
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TN();
    }
    
    void insert(string key, int val) {
        insert(root, 0, key, val);   
    }
    
    int sum(string prefix) {
        TN* head = root;
        for (char c : prefix) {
            if (!(head->letters)[c-'a']) return 0;
            head = (head->letters)[c-'a'];
        }
        return head->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */