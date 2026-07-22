class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start++]) != tolower(s[end--])) {
                return false;
            }
        }
        return true;
    }
};