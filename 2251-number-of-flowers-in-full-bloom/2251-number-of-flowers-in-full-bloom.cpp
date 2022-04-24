class Solution {
public:
    enum Ord : short { Start, Person, End };
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pair<int, Ord>> ev;
        ev.reserve(flowers.size() + persons.size());
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < persons.size(); ++i) {
            pos[persons[i]].push_back(i);
        }
        for (auto const& v : flowers) {
            ev.push_back({v[0], Ord::Start});
            ev.push_back({v[1], Ord::End});
        }
        set<pair<int, Ord>> cmp;
        for (auto const& p : persons) {
            cmp.insert({p, Ord::Person});
        }
        
        for (auto p : cmp)
            ev.push_back(p);
        sort(ev.begin(), ev.end());
        
        vector<int> ans(persons.size(), 0);
        int lvl = 0;
        
        for (auto [cp, T] : ev) {
            switch (T) {
                case Ord::Start:
                    ++lvl;
                    break;
                case Ord::Person:
                    for (int p : pos[cp])
                        ans[p] = lvl;
                    break;
                case Ord::End:
                    --lvl;
                    break;
            }
        }
        return ans;
    }
};