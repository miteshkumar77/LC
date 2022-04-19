// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        priority_queue<int,vector<int>, less<int>>minq; 
        priority_queue<int,vector<int>, greater<int>>maxq; 
        for (int i : nums) {
            minq.push(i); 
            maxq.push(i); 
            if (minq.size() > 3)
                minq.pop(); 
            if (maxq.size() > 3)
                maxq.pop(); 
        }
        
        vector<int> m; 
        while(!maxq.empty()) {
            m.push_back(maxq.top()); maxq.pop(); 
            cout << m.back() << ' ';
        }
        cout << endl; 
        
        vector<int> n; 
        while(!minq.empty()) {
            
            n.push_back(minq.top()); minq.pop(); 
        }
        return max(m[0] * m[1] * m[2], n[2] * n[1] * m[2]); 
        
        
    }
};