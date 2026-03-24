class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        unordered_set<string> bad;
        vector<string> res;

        function<bool(string&)> dfs = [&](string& word) {
            if (st.count(word)) {
                return true;
            }
            if (bad.count(word)) {
                return false;
            }

            int n = word.size();
            for (int i = 1; i < n; i++) {
                string left = word.substr(0, i);
                if (st.count(left)) {
                    string right = word.substr(i);
                    if (dfs(right)) {
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
            st.erase(words[i]);

            if (dfs(words[i])) {
                res.push_back(words[i]);
            }

            st.insert(words[i]);
        }

        return res;
    }
};