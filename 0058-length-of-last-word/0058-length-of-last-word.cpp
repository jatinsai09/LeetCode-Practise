class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, r = s.length() - 1;
        while (r >= 0 && s[r] == ' ') {
            --r;
        }
        while (r >= 0 && s[r] != ' ') {
            ++len;
            --r;
        }
        return len;
    }
};