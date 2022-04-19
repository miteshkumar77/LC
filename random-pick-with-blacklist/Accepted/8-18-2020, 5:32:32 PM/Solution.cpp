// https://leetcode.com/problems/random-pick-with-blacklist

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        n = N; 
        b.swap(blacklist); 
        sort(b.begin(), b.end()); 
    }
    
    int pick() {

        int k = rand() % (n - b.size()); 
        
        int L = 0; 
        int R = b.size() - 1; 
        while(L < R) {
            int mid = (L + R + 1)/2; 
            if (b[mid] - mid > k) {
                R = mid - 1; 
            } else {
                L = mid; 
            }
        }
        
        return L == R && b[L] - L <= k?k + L + 1 : k; 
        
    }
    
    
    int n; 
    vector<int> b; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */