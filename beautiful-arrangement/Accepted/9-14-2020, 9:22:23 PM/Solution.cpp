// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int countArrangement(int N) {
        
        
        int ans = 0; 
        vector<int> box(N + 1);
        for (int i = 1; i <= N; ++i) {
            box[i] = i; 
        }
        function<void(int)> bt = [&](int i) -> void {
            if (i == N + 1) {
                ++ans; 
                return;
            }
            
            for (int j = i; j <= N; ++j) {
                
                if ((box[j] % i == 0 || i % box[j] == 0)) {
                    swap(box[i], box[j]); 
                    bt(i + 1); 
                    swap(box[i], box[j]); 
                }
            }
        }; 
        
        bt(1); 
        return ans; 
    }
};