class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<array<int, 3>> evs;
        for (auto const& f : flowers) {
            evs.push_back({f[0], 0, 1});
            evs.push_back({f[1], 2, 1});
        }
        for (int i = 0; i < persons.size(); ++i)
            evs.push_back({persons[i], 1, i});
        vector<int> ans(persons.size());
        sort(evs.begin(), evs.end());
        int lvl{0};
        for (auto [pos, T, i] : evs) {
            switch (T) {
                case 0:
                    ++lvl;
                    break;
                case 1:
                    ans[i] = lvl;
                    break;
                case 2:
                    --lvl;
                    break;
            }
        }
        return ans;
    }
};