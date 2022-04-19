// https://leetcode.com/problems/task-scheduler

class Solution {
    
    
    
private: 
    
    class HashQueue {
     
        
    public: 
        
        HashQueue(int historySize) {
            n = historySize; 
            for (int i = 0; i < historySize; ++i) {
                queue.push_back(nullChar); 
            }
        }
        
        
        void push(char task) {
            
            if (hash.find(task) != hash.end()) {
                *(hash[task]) = nullChar; 
            }
            
            
            queue.push_back(task); 
            hash[task] = prev(queue.end()); 
            if (queue.front() != nullChar) {
                hash.erase(queue.front());
            }
            queue.pop_front(); 
            // cout << "S: " << this -> cooldownSize() << ' '; 
        }
        
        
        bool contains(char task) {
            return hash.find(task) != hash.end();  
        }
        
        
        
        void pop() {
            if (queue.size() != 0) {
                if (queue.front() != nullChar) {
                    hash.erase(queue.front()); 
                }
                queue.push_back(nullChar); 
                queue.pop_front(); 
                 
            }
            // cout << "S: " << this -> cooldownSize() << ' '; 
        }
        
        
        int cooldownSize() {
            return hash.size(); 
        }
        
        
    private: 
        
        unordered_map<char, list<char>::iterator> hash; 
        list<char> queue; 
        int n; 
        char nullChar = '$'; 
        
    };
    
    
    
    
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size(); 
        }
        unordered_map<char, int> task_cts; 
        int ans = 0; 
        for (char c : tasks) {
            ++task_cts[c]; 
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> mq;
        for (pair<char, int> p : task_cts) {
            mq.push(make_pair(p.second, p.first)); 
        }
        list<pair<int, char> > stak; 
        HashQueue hq(n); 
        
        
        while(!mq.empty()) {
            
            for (int i = 0; (i < n + 1) && !mq.empty(); ++i) {
                stak.push_front(mq.top()); mq.pop();  
            }
            // if (!mq.empty()) {
            //     pair<int, char> t = mq.top(); mq.pop(); 
            //     --t.first; 
            //     hq.push(t.second); 
            //     if (t.first != 0) {
            //         mq.push(t); 
            //     }
            //     // cout << ' ' << t.second << " | ";  
            // } else {
            //     hq.pop(); 
            //     // cout << " idle | "; 
            // }
            
            bool nothing = true;
            while(stak.size() != 0) {
                pair<int, char> t = stak.back();
                stak.pop_back(); 
                if (!hq.contains(t.second)) {
                    --t.first; 
                    hq.push(t.second); 
                    
                    // cout << t.second << " | "; 
                    nothing = false; 
                    ++ans; 
                } 
                
                if (t.first != 0) {
                    mq.push(t); 
                }
                
                
            }
            if (nothing) {
                // cout << "idle | "; 
                hq.pop(); 
                ++ans; 
            }
            
        } 

        return ans; 
    }
};