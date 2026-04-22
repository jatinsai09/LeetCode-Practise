class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        int n = queries[0].size();
        vector<string> res;

        for (auto& it1 : queries) {
            for (auto& it2 : dictionary) {
                int del = 0;
                for (int i = 0; i < n; i++) {
                    if (it1[i] != it2[i]) {
                        del++;
                    }
                    if (del > 2) {
                        break;
                    }
                }
                if (del <= 2) {
                    res.push_back(it1);
                    break;
                }
            }
        }
        return res;
    }
};