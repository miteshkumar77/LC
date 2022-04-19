// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int countArrangement(int n) {
        vector<int> box(n + 1);
        for (int i = 1; i <= n; ++i) {
            box[i] = i;
        }
        
        int ans = 0;
        
        function<void(int)> bt = [&](int i) -> void {
            if (i > n) {
                ++ans;
                return;
            }   
            
            for (int x = i; x <= n; ++x) {
                if (box[x] % i == 0 || i % box[x] == 0) {
                    swap(box[x], box[i]);
                    bt(i + 1);
                    swap(box[x], box[i]);
                }
            }
        };
        
        bt(1);
        return ans;
    }
};