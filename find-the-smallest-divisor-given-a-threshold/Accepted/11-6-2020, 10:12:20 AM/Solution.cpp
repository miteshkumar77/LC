// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        function<bool(int)> check = [&](int div) -> bool {
            int sum = 0;
            for (int i : nums) {
                sum += ceil((float)i/(float)div);
            }
            return sum <= threshold;
        };
        
        
        int l = 1;
        int r = 1e6;
        int mid;
        int ans = r;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};