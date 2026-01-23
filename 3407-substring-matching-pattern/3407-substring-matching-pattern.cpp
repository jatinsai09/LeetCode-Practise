class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find("*");
        string a = p.substr(0, x);
        string b = p.substr(x + 1);

        int i = s.find(a), j = s.rfind(b);

        return i != -1 && j != -1 && i + a.size() <= j;
    }
};