// https://leetcode.com/problems/leftmost-column-with-at-least-a-one

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        vector<int> vec = bm.dimensions(); 
        
        int last = vec[0] - 1;
        
        int ans = -1;
        int l = 0;
        int r = vec[1] - 1;
        int mid = 0;
        
        while(l <= r) {
            mid = l + (r - l)/2;
            if (bm.get(last, mid) == 1) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};