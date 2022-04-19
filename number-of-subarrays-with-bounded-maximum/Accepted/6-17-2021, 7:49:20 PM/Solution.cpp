// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

#define PR(var) cout << " " << #var << "("<< (var) << ")"

class Solution {
public:
    void push(int num, deque<array<int,2>>& dq) {
        array<int,2> a{num, 1};
        while(!dq.empty() && a[0] >= dq.front()[0]) {
            a[1] += dq.front()[1];
            dq.pop_front();
        }
        dq.push_front(a);
    }
    
    void pop(deque<array<int,2>>& dq) {
        if (--dq.back()[1] == 0) dq.pop_back();
    }
    
    int getExt(deque<array<int,2>>& dq) {
        return dq.empty() ? INT_MIN : dq.back()[0];
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int dp = 0;
        int n = nums.size();
        int ans = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= left && nums[i] <= right) {
                dp = ++len; 
            } else if (nums[i] > right) {
                len = 0;
                dp = 0;
            } else {
                ++len;
            }
            ans += dp;
        }
        return ans;
    }
};










