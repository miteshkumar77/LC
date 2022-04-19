// https://leetcode.com/problems/maximum-total-beauty-of-the-gardens

class Solution {
public:
    using ll = long long;
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        ll n = flowers.size();
        ll needed{0};
        ll full_ptr = n;
        for (ll i = n-1; i >= 0; --i) {
            needed = needed + max(0, target - flowers[i]);
                full_ptr = i;
        }
        ll needed_mv{0};
        ll pref_sum{0};
        ll ans = 0;
        ll partial_ptr{0};
        for (ll mv = 0; mv < (ll)target; ++mv) {
            while(partial_ptr < n && partial_ptr < full_ptr && flowers[partial_ptr] < mv) {
                pref_sum += flowers[partial_ptr++];
            }
            if (partial_ptr == 0 && mv > 0 && flowers[partial_ptr] <= mv) {
                pref_sum += flowers[partial_ptr++];
                full_ptr= max(partial_ptr, full_ptr);
            }
            needed_mv = mv * partial_ptr - pref_sum;
            if (needed_mv > newFlowers) break;
            while(needed_mv + needed > newFlowers) {
                needed -= max(0, target - flowers[full_ptr++]);
            }
            // cout << mv << ' ' << partial_ptr << ' ' << full_ptr << ' ' << (n - full_ptr) * full + ((ll)(partial_ptr != 0) * mv * partial) << endl;
            ans = max(ans, (n - full_ptr) * full + ((ll)(partial_ptr != 0) * mv * partial));
        }
        return ans;
    }
};