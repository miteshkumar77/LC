// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    struct TN {
        array<TN*, 26> childs;
        bool isEnd;
        TN() {
            fill(childs.begin(), childs.end(), nullptr);
            isEnd = false;
        }
    };
    void insert(TN* head, const string& s) {
        for (char c : s) {
            if (!(head->childs)[c-'a']) {
                (head->childs)[c-'a'] = new TN();
            }
            head = (head->childs)[c-'a'];
        }
        head->isEnd = true;
    }
    void traverse(TN* head, string& base, vector<string>& box) {
        if (head->isEnd) {
            box.push_back(base);
        }
        if (box.size() >= 3) return;
        for (int i = 0; i < 26; ++i) {
            if (!(head->childs)[i]) continue;
            base.push_back(i + 'a');
            traverse((head->childs)[i], base, box);
            base.pop_back();
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TN* head = new TN();
        for (const string& s : products) insert(head, s);
        vector<vector<string>> ans;
        string base;
        for (char c : searchWord) {
            base.push_back(c);
            ans.push_back({});
            if (head) {
                head = (head->childs)[c-'a'];
                traverse(head, base, ans.back());
            }
        }
        return ans;
    }
};
















