// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); 
        int ans = people.size(); 
        int L = 0; 
        int R = ans - 1; 
        
        while(L < R) {
            if (people[R] + people[L] > limit) {
                --R; 
            } else {
                ans -= 1; 
                ++L; 
                --R; 
            }
        }
        return ans; 
    }
};