// https://leetcode.com/problems/sliding-window-maximum

class Solution {
    typedef pair<int, int> pii; 

    
private: 
    class MonoQueue {
    public: 
        deque<pii> monoq; 
        MonoQueue() {
            monoq = deque<pii>(); 
        }
        
        void enqueue(int val) {
            pii newp {val, 1}; 
            while(!monoq.empty() && val > monoq.back().first) {
                newp.second += monoq.back().second; 
                monoq.pop_back(); 
            }
            
            if (!monoq.empty() && val == monoq.back().first) {
                monoq.back().second += newp.second; 
            } else {
                monoq.push_back(newp); 
            }
        }
        
        int pop() {
            
            int ret = monoq.front().first; 
            if ((--monoq.front().second) == 0) {
                monoq.pop_front(); 
            }
            return ret; 
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue mq;  
        for (int i = 0; i < k; ++i) {
            mq.enqueue(nums[i]); 
        }
        
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i < ans.size() - 1; ++i) {
            ans[i] = mq.pop(); 
            mq.enqueue(nums[i + k]); 
        } 
        ans[ans.size() - 1] = mq.pop(); 
        return ans; 
    }
};