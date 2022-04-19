// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        list<int> lst;
        unordered_map<char, list<int>::iterator> mp; 
        int i = 0;
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                lst.push_back(i);
                mp[c] = prev(lst.end());
            } else {
                if (mp[c] != lst.end()) {
                    lst.erase(mp[c]);
                    mp[c] = lst.end();
                }
            }
            ++i;
        }
        if (lst.size() == 0) {
            return -1;
        }
        return lst.front();
    }
};