class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), odd = 0;

        unordered_map<char, int> mp;
        for (auto &ch: s) {
            mp[ch]++;
            if (mp[ch] % 2 == 1) {
                odd++;
            } else {
                odd--;
            }
        }

        if (odd > 1) {
            return n - odd + 1;
        }
        return n;
    }
};