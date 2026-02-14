class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";

        for (auto &w: words) {
            int wt = 0;
            for (auto &c: w) {
                wt += weights[c - 'a'];
                wt %= 26;
            }

            res += char('z' - wt);
        }

        return res;
    }
};