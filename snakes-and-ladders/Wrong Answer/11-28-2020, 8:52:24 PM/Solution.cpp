// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        int last = N * N; 
        
        function<pair<int,int>(int)> getCoords = [&](int num) -> pair<int,int> {
            int row = N - (num - 1)/N - 1;
            int col;
            if (row % 2 == 1) {
                col = (num - 1) % N;
            } else {
                col = N - (num - 1) % N - 1;
            }
            // cout << num << ": row: " << row << " col: " << col << endl;
            return make_pair(row, col); 
        };
        
        // getCoords(1);
        // getCoords(last);
        
        queue<pair<int,int>> bfsq; 
        bfsq.push(make_pair(1, 0)); 
        unordered_set<int> visited;
        while(!bfsq.empty()) {
            auto top = bfsq.front(); 
            bfsq.pop(); 
            
            int currentIndex = top.first;
            int currentDist = top.second;
            
            if (visited.find(currentIndex) != visited.end()) {
                continue;
            }
            
            if (currentIndex == last) {
                return currentDist;
            }
            visited.insert(currentIndex);
            
            
            
            for (int i = 1; i + currentIndex <= last && i <= 6; ++i) {
                auto coords = getCoords(currentIndex + i);
                int gridVal = board[coords.first][coords.second];
                int nextIndex;
                if (gridVal != -1) {
                    nextIndex = gridVal;
                } else {
                    nextIndex = currentIndex + i;
                }
                bfsq.push(make_pair(nextIndex, currentDist + 1)); 
            }
        }
        
        return -1; 
    }
};