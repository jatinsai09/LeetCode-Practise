class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int s_len = s.length(), p_len = p.length();

        if (s_len < p_len) {
            return {};
        }

        vector<int> freq_p(26, 0), window(26, 0);

        for (int i = 0; i < p_len; i++) {
            freq_p[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        vector<int> res;
        if (freq_p == window) {
            res.push_back(0);
        }

        for (int i = p_len; i < s_len; i++) {
            window[s[i - p_len] - 'a']--;
            window[s[i] - 'a']++;

            if (freq_p == window) {
                res.push_back(i - p_len + 1);
            }
        }
        return res;
    }
};