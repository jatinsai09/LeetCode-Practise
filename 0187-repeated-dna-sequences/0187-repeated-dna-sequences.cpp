class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<char, int> mc;
        mc['A'] = 0;
        mc['C'] = 1;
        mc['G'] = 2;
        mc['T'] = 3;

        map<int, int> seen;
        vector<string> res;

        int h = 0, msk = (1 << 20) - 1;
        for (int i = 0; i < n; i++) {
            h = (h << 2) + mc[s[i]];
            h = h & msk;
            if (i >= 9) {
                if (++seen[h] == 2) {
                    string sb = s.substr(i - 9, 10);
                    res.push_back(sb);
                } 
            }
        }
        return res;
    }
};