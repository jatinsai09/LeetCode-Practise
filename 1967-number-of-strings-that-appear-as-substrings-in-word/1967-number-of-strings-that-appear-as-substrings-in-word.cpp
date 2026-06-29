class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;

        for (auto &s : patterns) {
            if (word.find(s) != string::npos) {
                res++;
            }
        }

        return res;
    }
};