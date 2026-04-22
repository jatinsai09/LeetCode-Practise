class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        int n = queries[0].size();
        vector<string> res;

        for (auto& it1 : queries) {
            for (auto& it2 : dictionary) {
                int del = 0;
                for (int i = 0; i < n && del < 3; i++) {
                    del += (it1[i] != it2[i]);
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