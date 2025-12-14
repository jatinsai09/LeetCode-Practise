class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), vow = 0;
        string v = "aeiou";

        int i = 0; 
        while (i < n && s[i] != ' ') {
            if (v.find(s[i]) != string::npos) {
                vow++;
            }
            i++;
        }

        int req = vow;
        i++;
        int j = i;
        while (i < n) {
            vow = 0;
            while (i < n && s[i] != ' ') {
                if (v.find(s[i]) != string::npos) {
                    vow++;
                }
                i++;
            }
            int ti = i - 1, tj = j;
            if (vow == req) {
                while (ti > tj) {
                    swap(s[ti--], s[tj++]);
                }
            }
            i++;
            j = i;
        }
        return s;
    }
};