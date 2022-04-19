// https://leetcode.com/problems/task-scheduler

class Solution {    
    
    
    
    
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0; 
        priority_queue<int, vector<int>, less<int>> pq; 
        unordered_map<char, int> ct; 
        for (char c : tasks) {
            ct[c]++;
        }
        
        for (pair<char, int> p : ct) {
            pq.push(p.second); 
        }
        queue<int> awaited; 
        while(!pq.empty()) {
            
            int k = n + 1; 
            while(k > 0 && !pq.empty()) {
                awaited.push(pq.top() - 1); pq.pop();
                --k;
                ++ans;
            }
            
            while(!awaited.empty()) {
                if (awaited.front() > 0) {
                    pq.push(awaited.front()); 
                }
                awaited.pop(); 
            }
            
            if (pq.empty()) {
                break;
            }
            
            ans += k; 
            
        }      
        
        return ans; 
        
    }
};