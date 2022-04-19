// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        arr.insert(arr.begin(), 0);
        
        int l = 0;
        int r = arr.size() - 1;
        int mid;
        int ans = l;
        
        while(l <= r) {
            mid = l + (r - l)/2;
            if (arr[mid] - mid >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
                ans = mid;
            }
        }
                
        return arr[ans] + (k - arr[ans] + ans);
        
    }
};