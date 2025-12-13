class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<string> res;
        vector<int> ind;
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
                    ind.push_back(i);
                }
            }
        }

        sort(begin(ind), end(ind), [&](int i, int j) {
            if (businessLine[i] != businessLine[j]) {
                return businessLine[i] < businessLine[j];
            }
            return code[i] < code[j];
        });

        for (auto& i : ind) {
            res.push_back(code[i]);
        }

        return res;
    }
};