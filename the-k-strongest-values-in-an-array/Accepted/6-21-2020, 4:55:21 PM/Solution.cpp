// https://leetcode.com/problems/the-k-strongest-values-in-an-array

class Solution {
public:
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end()); 
        vector<int> ans; ans.reserve(k); 
        int m = arr[(arr.size() - 1)/2]; 
        auto compare = [m] (int& a, int& b) -> bool {
            if (abs(a - m) > abs(b - m)) {
                return true; 
            } else if (abs(a - m) == abs(b - m)) {
                return a > b; 
            } else {
                return false; 
            }
        }; 
        priority_queue<int, vector<int>, decltype(compare)> pq(compare); 
        for (int i = 0; i < arr.size(); ++i) {
            pq.push(arr[i]); 
            if (pq.size() > k) {
                pq.pop(); 
            }
        }
        
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top()); pq.pop(); 
        }
        return ans; 
        
    }
};