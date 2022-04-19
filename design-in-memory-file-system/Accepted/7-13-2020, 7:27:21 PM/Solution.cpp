// https://leetcode.com/problems/design-in-memory-file-system

class FileSystem {
    
private: 
    class Level {
    public:
        unordered_map<string, pair<string, Level*> > dir;
        
    };
    
    
    
    vector<string> tokenizePath(string path) {
        string s = ""; 
        vector<string> ans; 
        for (int i = 1; i < path.length(); ++i) {
            if (path[i] == '/') {
                ans.push_back(s); 
                s = ""; 
            } else {
                s += path[i]; 
            }
        }
        if (path.length() > 1) {
            ans.push_back(s); 
        }
         
        return ans; 
    }
    
    Level* root; 
public:
    FileSystem() {
        root = new Level(); 
    }
    
    vector<string> ls(string path) {
        Level* pter = root; 
        vector<string> tP = tokenizePath(path); 
        
        for (int i = 0; i < (signed int)(tP.size() - 1); ++i) {
            pter = (pter -> dir)[tP[i]].second;  
        }
        
        
        if (!(tP.size()) == 0 && (pter -> dir).find(tP.back()) != (pter -> dir).end() &&
           (pter -> dir)[tP.back()].second == nullptr) {
            return vector<string>{tP.back()};
        } else {
            if (!tP.size() == 0) {
                pter = (pter -> dir)[tP.back()].second; 
            }
            vector<string> ans; 
            for (auto p : (pter -> dir)) {
                ans.push_back(p.first);
            }
            sort(ans.begin(), ans.end()); 
            return ans; 
        }
    }
    
    void mkdir(string path) {
        Level* pter = root; 
        vector<string> tP = tokenizePath(path); 
        for (string s : tP) {
            if ((pter -> dir).find(s) != (root -> dir).end()) {
                if (!(pter -> dir)[s].second) {
                    (pter -> dir)[s].second = new Level(); 
                }
                pter = (pter -> dir)[s].second; 
            } else {
                Level* newLevel = new Level(); 
                (pter -> dir)[s] = make_pair("", newLevel); 
                pter = newLevel; 
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Level* pter = root; 
        vector<string> tP = tokenizePath(filePath); 
        for (int i = 0; i < tP.size() - 1; ++i) {
            pter = (pter -> dir)[tP[i]].second; 
        }
        
        if ((pter -> dir).find(tP.back()) != (pter -> dir).end()) {
            (pter -> dir)[tP.back()].first += content; 
        } else {
            (pter -> dir)[tP.back()] = make_pair(content, nullptr);
        }
    }
    
    string readContentFromFile(string filePath) {
        Level* pter = root; 
        vector<string> tP = tokenizePath(filePath); 
        for (int i = 0; i < tP.size() - 1; ++i) {
            pter = (pter -> dir)[tP[i]].second; 
        }
        return (pter -> dir)[tP.back()].first; 
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */