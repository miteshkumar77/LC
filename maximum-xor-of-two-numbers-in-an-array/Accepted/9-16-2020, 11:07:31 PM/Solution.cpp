// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
    
private:
    
    struct TN {
        
        TN () {
            fill(next.begin(), next.end(), nullptr); 
            isEnd = false; 
        }
        array<TN*, 2> next; 
        bool isEnd; 
    };
    
    
    void insert(int num, TN* head) {
        
        for (int bit = 1 << 30; bit != 0; bit >>= 1) {
            if (!head -> next[!!(num & bit)]) {
                head -> next[!!(num & bit)] = new TN(); 
            }
            head = head -> next[!!(num & bit)]; 
        }
        head -> isEnd = true; 
    }
    
    int maxdif(int num, TN* head) {
        int ans = 0;  
        for (int bit = 1 << 30; bit != 0; bit >>= 1) {
            if (head -> next[!(num & bit)]) {
                head = head -> next[!(num & bit)];
                ans += bit; 
            } else {
                head = head -> next[!!(num & bit)]; 
            }
        }
        return ans; 
    }
    
public:
    
    
    int findMaximumXOR(vector<int>& nums) { 
        TN* head = new TN(); 
        insert(nums[0], head);
        int ans = 0; 
        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, maxdif(nums[i], head));
            insert(nums[i], head); 
        }
        return ans; 
    }
};