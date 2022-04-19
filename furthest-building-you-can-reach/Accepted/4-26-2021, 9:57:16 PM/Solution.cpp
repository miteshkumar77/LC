// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // [4,2,7,6,9,14,12] bricks = 5, ladders = 1
        //    j b j l 
        //      5
        
        /* 
           8    5   15  2   16
        [4,12,2,7,3,18,20,3,19] bricks = 3 ladders = 0
            l j b j  l  b j  x
             
        
        */


        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i + 1 < n; ++i) {
            if (heights[i] < heights[i + 1]) {
                pq.push(heights[i + 1] - heights[i]);
                
                if (ladders) {
                    --ladders;
                } else {
              
                    bricks -= pq.top();
                    if (bricks < 0) {
                        return i;
                    }
                    pq.pop();
                }
            }
        }
        return n - 1;
    }
};