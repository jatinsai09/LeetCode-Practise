class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        vector<int> f(26, 0);

        for (const auto& c : magazine) {
            f[c - 'a']++;
        }

        for (const auto& c : ransomNote) {
            if (f[c - 'a'] == 0) {
                return false;
            }
            f[c - 'a']--;
        }
        return true;
    }
};