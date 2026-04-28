class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) { 
        int n = s.size(); 
        vector<int> f(26), fi(26);
        vector<char> v;

        for (int i = n - 1; i >= 0; i--) {
            if (isVowel(s[i])) {
                fi[s[i] - 'a'] = i;
                f[s[i] - 'a']++;
                v.push_back(s[i]);
            }
        }

        sort(begin(v), end(v), [&](char c1, char c2){
            if (f[c1 - 'a'] == f[c2 - 'a']) {
                return fi[c1 - 'a'] < fi[c2 - 'a'];
            }
            return f[c1 - 'a'] > f[c2 - 'a'];
        });

        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = v[ind++];
            }
        }

        return s;
    }
};