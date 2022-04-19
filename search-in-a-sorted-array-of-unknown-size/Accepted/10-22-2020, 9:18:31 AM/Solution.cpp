// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

#define INV 2147483647
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 1e4;
        int lindex = 1e4;
        int mid;
//         while(l <= r) {
//             mid = l + (r - l)/2;
//             if (reader.get(mid) == INV) {
//                 r = mid - 1;
//             } else {
//                 lindex = mid;
//                 l = mid + 1;
//             }
//         }
        
//         cout << lindex << endl;
        
        l = 0;
        r = lindex;
        int tmp;
        while(l <= r) {
            mid = l + (r - l)/2;
            tmp = reader.get(mid);
            if (tmp < target) {
                l = mid + 1;
            } else if (tmp > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
        
    }
};