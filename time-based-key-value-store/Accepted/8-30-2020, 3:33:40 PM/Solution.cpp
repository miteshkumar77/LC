// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key].push_back(make_pair(timestamp, value)); 
    }
    
    string get(string key, int timestamp) {
        const vector<pair<int, string>>& file = table[key]; 
        int L = 0; 
        int R = file.size() - 1; 
        int ans = -1; 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (file[mid].first > timestamp) {
                R = mid - 1; 
            } else {
                ans = mid; 
                L = mid + 1; 
            }
        }
        if (ans == -1) {
            return ""; 
        } else {
            return file[ans].second; 
        }
    }
    
    unordered_map<string, vector<pair<int, string>>> table; 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */