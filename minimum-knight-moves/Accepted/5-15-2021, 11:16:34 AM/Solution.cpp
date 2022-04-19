// https://leetcode.com/problems/minimum-knight-moves

class Solution {
public:
    int minKnightMoves(int x, int y) {
        
        auto compare = [&] (pair<array<int, 2>, int>& a, pair<array<int, 2>, int>& b) -> bool {
            int dista = (a.first[0] - x) * (a.first[0] - x) + (a.first[1] - y) * (a.first[1] - y); 
            int distb = (b.first[0] - x) * (b.first[0] - x) + (b.first[1] - y) * (b.first[1] - y); 
            
            if (dista <= 10 && distb <= 10) {
                return a.second > b.second; 
            } else {
                return dista > distb; 
            }
        };
        
        array<int, 8> dx{1, 1, 2, 2, -1, -1, -2, -2}; 
        array<int, 8> dy{2, -2, 1, -1, 2, -2, 1, -1};
        priority_queue<pair<array<int, 2>, int>, vector<pair<array<int, 2>, int>>, decltype(compare)> q(compare); 
        // queue<pair<array<int, 2>, int>> q; 
        unordered_map<int, unordered_set<int>> visited; 
        q.push(make_pair(array<int, 2>{0, 0}, 0)); 
        
        while(!q.empty()) {
            auto [pos, dist] = q.top(); q.pop(); 
            
            if (visited.find(pos[0]) == visited.end() || visited[pos[0]].find(pos[1]) == visited[pos[0]].end()) {
                if (pos[0] == x && pos[1] == y) {
                    return dist;
                }
                visited[pos[0]].insert(pos[1]); 
                for (int i = 0; i < 8; ++i) {
                    q.push(make_pair(array<int, 2>{pos[0] + dx[i], pos[1] + dy[i]}, dist + 1)); 
                }
            }
        }
        return 0; 
        
    }
};