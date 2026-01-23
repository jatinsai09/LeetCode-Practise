class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string joined;
        for (int i = 0; i < words.size(); i++) {
            joined += words[i];
            joined += " ";
        }

        vector<string> substr;
        for (const auto& w : words) {
            int count = 0;
            size_t pos = 0;
            while ((pos = joined.find(w, pos)) != string::npos) {
                count++;
                pos += w.length();
            }
            if (count >= 2) {
                substr.push_back(w);
            }
        }
        return substr;
    }
};