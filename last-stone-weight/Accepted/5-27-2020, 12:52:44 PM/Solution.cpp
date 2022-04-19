// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> sheep(stones.begin(), stones.end()); 
        while(sheep.size() > 1) {
            int tmp = sheep.top(); 
            sheep.pop(); 
            int tmp2 = sheep.top(); 
            sheep.pop(); 
            if (tmp != tmp2) {
                sheep.push(max(tmp2, tmp) - min(tmp2, tmp)); 
            }
        }
        
        if (sheep.size() == 0) {
            return 0; 
        } else {
            return sheep.top(); 
        }
    }
};