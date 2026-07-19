class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size(), sft = 0;
        for (auto &i: shifts) {
            sft = (sft + i) % 26;
        }

        for (int i = 0; i < n; i++) {
            int og = (s[i] - 'a');
            int mg = (og + sft) % 26;

            s[i] = char('a' + mg);

            sft = ((sft - shifts[i]) % 26 + 26) % 26;
        }
        return s;
    }
};