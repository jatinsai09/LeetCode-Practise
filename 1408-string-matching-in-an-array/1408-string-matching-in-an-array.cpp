class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string joined = "";
        for (string w : words) {
            joined += w + " ";
        }

        vector<string> result;
        for (auto& w : words) {
            int count = 0;

            size_t pos = joined.find(w);
            while (pos != string::npos) {
                count++;
                pos = joined.find(w, pos + w.length());
            }

            if (count >= 2) {
                result.push_back(w);
            }
        }

        return result;
    }
};