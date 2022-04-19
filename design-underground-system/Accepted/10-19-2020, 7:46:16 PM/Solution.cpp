// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        loc[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int delta = t - loc[id].second;
        sum[loc[id].first][stationName] += delta;
        ++total[loc[id].first][stationName];
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double)sum[startStation][endStation])/total[startStation][endStation];
    }
    
    unordered_map<string, unordered_map<string, int>> sum;
    unordered_map<string, unordered_map<string, int>> total;
    
    unordered_map<int, pair<string,int>> loc; 
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */