class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<string> res;
        set<string> s = {"electronics", "grocery", "pharmacy", "restaurant"};

        for (int i = 0; i < n; i++) {
            if (!code[i].empty() && isActive[i] &&
                s.find(businessLine[i]) != s.end()) {
                bool yes = true;
                for (auto& c : code[i]) {
                    if (!isalnum(c) && c != '_') {
                        yes = false;
                        break;
                    }
                }
                if (yes) {
                    res.push_back(businessLine[i][0] + code[i]);
                }
            }
        }

        sort(begin(res), end(res));

        for (auto& s : res) {
            s = s.substr(1);
        }

        return res;
    }
};