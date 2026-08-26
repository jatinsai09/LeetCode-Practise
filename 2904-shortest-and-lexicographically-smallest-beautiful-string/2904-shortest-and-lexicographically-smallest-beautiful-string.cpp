class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), c1 = 0;

        vector<int> p1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                p1.push_back(i);
                c1++;
            }
        }

        if (c1 < k) {
            return "";
        }

        string res = "";
        for (int i = 0; i + k <= c1; i++) {
            int st = p1[i], end = p1[i + k - 1];

            string cur = s.substr(st, end - st + 1);

            if (res.empty() || cur.size() < res.size() ||
                (cur.size() == res.size() && cur < res)) 
            {
                res = cur;
            }
        }

        return res;
    }
};