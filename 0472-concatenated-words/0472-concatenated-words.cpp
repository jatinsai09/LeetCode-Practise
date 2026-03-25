class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        unordered_set<string> bad;
        vector<string> res;

        function<bool(string&)> dfs = [&](string& word) {
            if (bad.count(word)) {
                return false;
            }

            int n = word.size();
            for (int i = 1; i < n; i++) {
                string left = word.substr(0, i);
                if (st.count(left)) {
                    string right = word.substr(i);
                    if (st.count(right) || dfs(right)) {
                        return true;
                    } else {
                        bad.insert(right);
                    }
                }
            }

            bad.insert(word);
            return false;
        };

        for (int i = 0; i < words.size(); i++) {
            if (dfs(words[i])) {
                res.push_back(words[i]);
            }
        }

        return res;
    }
};