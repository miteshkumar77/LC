// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class Solution {
public:
    string getHappyString(int n, int k) {
        
        int x = 0;
        string ans;
        string box;
        function<void()> dfs = [&]() -> void {
            if (box.length() == n) {
                ++x;
                if (x == k) {
                    ans = box;
                }
                return;
            }
            if (x == k) return;
            for (char i = 'a'; i <= 'c'; ++i) {
                if (box.size() != 0 && box.back() == i) {
                    continue;
                }
                box.push_back(i);
                dfs(); 
                box.pop_back();
                if (x == k) return;
            }
        };
        dfs();
        
        return ans;
    }
};