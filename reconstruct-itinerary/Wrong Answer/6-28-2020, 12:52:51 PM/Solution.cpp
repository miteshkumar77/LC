// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, string> itinerary; 
        for (vector<string> trip : tickets) {
            itinerary[trip[0]] = trip[1]; 
        }
        
        vector<string> ans {"JFK"}; 
        for (int i = 0; i < tickets.size(); ++i) {
            ans.push_back(itinerary[ans.back()]);
        }
        return ans; 
    }
};