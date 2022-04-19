// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int top = q.front(); q.pop();
            if (visited.find(top) != visited.end()) {
                continue;
            }
            visited.insert(top);
            for (int neighbor : rooms[top]) {
                q.push(neighbor);
            }
        }
        return visited.size() == rooms.size();
    }
};