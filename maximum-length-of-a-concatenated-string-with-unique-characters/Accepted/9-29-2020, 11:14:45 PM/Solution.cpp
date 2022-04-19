// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        vector<string> reduced;
        for (string s : arr) {
            if (unordered_set<char>(s.begin(), s.end()).size() == s.length()) {
                reduced.push_back(s);
            }
        }
        arr.swap(reduced);
        unordered_set<char> seen;
        unsigned int ans = 0;
        function<void(int)> bt = [&](int i) -> void {
            if (i == arr.size()) {
                ans = max(ans, (unsigned int)seen.size());
                return;
            }
            bool stillUnique = true;
            for (char c : arr[i]) {
                if (seen.find(c) != seen.end()) {
                    stillUnique = false;
                }
            }
            if (stillUnique) {
                for (char c : arr[i]) {
                    seen.insert(c);
                }
                bt(i + 1);
                for (char c : arr[i]) {
                    seen.erase(c);
                }
            }
            bt(i + 1);
        };
        
        bt(0);
        return ans; 
    }
};