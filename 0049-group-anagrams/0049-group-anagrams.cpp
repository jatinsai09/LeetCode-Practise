class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs) {
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& [key, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};