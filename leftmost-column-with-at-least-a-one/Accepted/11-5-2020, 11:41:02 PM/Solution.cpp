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

/*

[[1,1,1,1,1],
 [0,0,0,1,1],
 [0,0,1,1,1],
 [0,0,0,0,1],
 [0,0,0,0,0]]

*/

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        vector<int> vec = bm.dimensions(); 
        
        int height = vec[0];
        int width  = vec[1];
        
        int l = 0;
        int r = width - 1;
        function<bool(int)> check = [&](int col) -> bool {
            for (int i = 0; i < height; ++i) {
                if (bm.get(i, col) == 1) {
                    return true;
                }
            }    
            
            return false;
        };
        
        int ans = -1;
        int mid;
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