class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        int f[26] = {0};
        for (const auto& c : s) {
            f[c - 'a']++;
        }

        string fst = "";
        char ch = '#';
        for (int i = 0; i < 26; i++) {
            if (f[i] & 1) {
                ch = 'a' + i;
            }

            for (int j = 0; j < f[i] / 2; j++) {
                fst += ('a' + i);
            }
        }
        
        string sec = fst;
        reverse(begin(sec), end(sec));

        if (ch != '#') {
            fst += ch;
        }

        return fst + sec;
    }
};