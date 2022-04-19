// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); 
        queue<int> q; 
        int res = 0; 
        for (int i : people) {
            if (!q.empty() && limit - q.front() >= i) {
                q.pop(); 
                ++res;
            } else {
                q.push(i); 
            }
        }
        return q.size() + res; 
    }
};