// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
    
private:
    
    class SW {
        
    public:
        
        SW(function<bool(int,int)> comparator) {
            cmp = comparator; 
            m_size = 0; 
        }
        
        
        int getExt() {
            if (dq.empty()) {
                cout << "Popped empty deque!!!" << endl; 
            }
            return dq.front().first; 
        }
        
        int size() {
            return m_size; 
        }
        bool empty() {
            return dq.empty(); 
        }
        void push(int i) {
            ++m_size;
            pair<int,int> nw = make_pair(i, 1); 
            while(!dq.empty() && cmp(nw.first, dq.back().first)) {
                nw.second += dq.back().second; 
                dq.pop_back(); 
            }
            dq.push_back(nw); 
        }
        
        void pop() {
            --m_size;
            --dq.front().second; 
            if (dq.front().second == 0) {
                dq.pop_front(); 
            }
        }
        
    private:
        
        int m_size; 
        deque<pair<int,int>> dq; 
        function<bool(int,int)> cmp; 
    };
public:
    int longestSubarray(vector<int>& nums, int limit) {
        SW minq([](int a, int b) -> bool {
            return a <= b;     
        });
        
        SW maxq([](int a, int b) -> bool {
            return a >= b;     
        });
        
        int ans = 1; 
        function<int()> getdiff = [&]() -> int {
            return maxq.getExt() - minq.getExt();     
        };        
        for (int i = 0; i < nums.size(); ++i) {
            minq.push(nums[i]); 
            maxq.push(nums[i]); 
            while(!minq.empty() && getdiff() > limit) {
                minq.pop(); 
                maxq.pop(); 
            }
            if (!minq.empty()) {
                ans = max(ans, minq.size()); 
            }
        }
        return ans; 
        
    }
};
























