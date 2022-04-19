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
        int lindex = 0;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (reader.get(mid) == INV) {
                r = mid - 1;
            } else {
                lindex = mid;
                l = mid + 1;
            }
        }
        
        l = 0;
        r = lindex;
        while(l <= r) {
            mid = l + (r - l)/2;
            mid = reader.get(mid);
            if (mid < target) {
                l = mid + 1;
            } else if (mid > target) {
                r = mid - 1;
            } else {
                return l + (r - l)/2;
            }
        }
        return -1;
        
    }
};