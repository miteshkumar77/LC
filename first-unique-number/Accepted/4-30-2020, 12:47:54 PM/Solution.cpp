// https://leetcode.com/problems/first-unique-number

typedef list<int> q_type; 
typedef unordered_map<int, q_type::iterator> m_type; 

class FirstUnique {
public:
    
    q_type q; 
    m_type m; 
    FirstUnique(vector<int>& nums) {
        q = q_type(); 
        m = m_type(); 
        for (int num : nums) {
            add(num); 
        }
    }
    
    int showFirstUnique() {
        if (q.size() == 0) {
            return -1; 
        } else {
            return q.front(); 
        }
    }
    
    void add(int value) {
        pair<m_type::iterator, bool> added = m.insert(pair<int, q_type::iterator>(value, q.end())); 
        
        if (!added.second) {
            if (added.first -> second == q.end()) {
                return; 
            }
            q.erase(added.first -> second); 
            added.first -> second = q.end(); 
            return; 
        }
        
        q.push_back(value); 
        added.first -> second = --q.end(); 
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */