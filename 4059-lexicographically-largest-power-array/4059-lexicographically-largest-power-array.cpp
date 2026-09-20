class Solution {
public:
    vector<int> largestPower(vector<int>& nums){
        vector<vector<int>> dp = {nums};

        vector<int> pwr(15);
        for (int bit = 14; bit >= 0; bit--) {
            vector<vector<int>> ndp;
            int cur = 0, f = 1;

            for (auto &g: dp) {
                if (!f) {
                    ndp.push_back(g);
                } else {
                    vector<int> p1, p0;

                    for (auto &i: g) {
                        if ((i >> bit) & 1) {
                            p1.push_back(i);
                        } else {
                            p0.push_back(i);
                        }
                    }

                    cur += p1.size();
                    if (!p1.empty()) {
                        ndp.push_back(p1);
                    }
                    if (!p0.empty()) {
                        ndp.push_back(p0);
                        f = 0;
                    }
                }
            }

            pwr[14 - bit] = cur;
            dp = ndp;
        }

        return pwr;
    }
};