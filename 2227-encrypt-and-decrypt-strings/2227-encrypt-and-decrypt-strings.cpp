class Encrypter {
public:
    vector<char> keys;
    vector<string> values;
    vector<string> dictionary;
    array<int, 26> key_map;
    unordered_map<string, vector<char>> val_map;
    struct TN {
        bool isEnd{false};
        array<TN*, 26> children;
    };
    TN* root{nullptr};
    
    void insert(string const& s) {
        TN* cur = root;
        for (char c : s) {
            if (!(cur->children)[c-'a']) {
                (cur->children)[c-'a'] = new TN();
            }
            cur = (cur->children)[c-'a'];
        }
        cur->isEnd = true;
    }
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) : keys{keys}, values{values}, dictionary{dictionary} {
        root = new TN();
        fill(key_map.begin(), key_map.end(), -1);
        for (int i = 0; i < keys.size(); ++i) {
            key_map[keys[i]-'a'] = i;
        }
        for (int i = 0; i < values.size(); ++i) {
            val_map[values[i]].push_back(keys[i]);
        }
        for (string const& s : dictionary)
            insert(s);
    }
    
    string encrypt(string word1) {
        string ans;
        for (char & c : word1) {
            if (key_map[c-'a'] == -1) {
                return "";
            }
            ans += values[key_map[c-'a']];
        }
        return ans;
    }
    
    int helper(string const& word, int i, TN* cur) {
        if (!cur) return 0;
        if (i == word.length() && cur->isEnd) {
            return 1;
        }
        string two = word.substr(i, 2);
        if (!val_map.count(two)) return 0;
        int ans{0};
        for (char c : val_map[two]) {
            ans += helper(word, i + 2, (cur->children)[c-'a']);
        }
        return ans;
    }
    
    int decrypt(string word2) {
        return helper(word2, 0, root);
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */