// https://leetcode.com/problems/rank-transform-of-a-matrix

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        int N = n * m;
        cout << N << endl;
        vector<int> parent(N, -1);
        vector<int> rank(N, -1);
        for (int i = 0; i < N; ++i) parent[i] = i;
        function<int(int)> find = [&](int node) -> int {
            if (parent[node] == node) return node;
            parent[node] = find(parent[node]);
            return parent[node];
        };
        
        function<bool(int,int)> onion = [&](int a, int b) -> bool {
            int pa = find(a); int pb = find(b);
            if (pa == pb) return false;
            parent[pa] = pb;
            return true;
        };
        vector<unordered_map<int,int>> r(n);
        vector<unordered_map<int,int>> c(m);
        vector<int> nodes(N); for (int i = 0; i < nodes.size(); ++i) nodes[i] = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!r[i].count(matrix[i][j])) {
                    r[i][matrix[i][j]] = i * m + j;
                } else {
                    onion(r[i][matrix[i][j]], i * m + j);
                }
                if (!c[j].count(matrix[i][j])) {
                    c[j][matrix[i][j]] = i * m + j;
                } else {
                    onion(c[j][matrix[i][j]], i * m + j);
                }
            }
        }
        for (int i : nodes) find(i);
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return matrix[parent[a]/m][parent[a]%m] < matrix[parent[b]/m][parent[b]%m] || 
                   (matrix[parent[a]/m][parent[a]%m] == matrix[parent[b]/m][parent[b]%m] && parent[a] < parent[b]);
        });
        int prev = 0;
        vector<int> lowest_r(n, 0);
        vector<int> lowest_c(m, 0);
        rank[find(nodes[0])] = 1;
        int iters = 0;
        for (int i = 1; i <= N; ++i) {
            ++iters;
            if (i == N || parent[nodes[i]] != parent[nodes[i-1]]) {
                for (int j = prev; j < i; ++j) {
                    ++iters;
                    lowest_r[nodes[j]/m] = max(lowest_r[nodes[j]/m], rank[parent[nodes[j]]]);
                    lowest_c[nodes[j]%m] = max(lowest_c[nodes[j]%m], rank[parent[nodes[j]]]);
                }
                prev = i;
            }
            if (i < N)
                rank[parent[nodes[i]]] = max(rank[parent[nodes[i]]], max(lowest_r[nodes[i]/m], lowest_c[nodes[i]%m]) + 1);
        }
        cout << iters << endl;
        for (int i : nodes) {
            matrix[i/m][i%m] = rank[parent[i]];
        }
        return matrix;
    }
};