class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string joined = "";
        for (auto& w : words) {
            joined += w + " ";
        }

        vector<string> res;
        for (auto& w : words) {
            int count = 0;

            size_t pos = joined.find(w);
            while (pos != string::npos) {
                count++;
                pos = joined.find(w, pos + w.length());
            }

            if (count >= 2) {
                res.push_back(w);
            }
        }

        return res;
    }
};