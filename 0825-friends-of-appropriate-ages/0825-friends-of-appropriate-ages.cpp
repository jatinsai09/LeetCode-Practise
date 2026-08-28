class Solution {
public:
    int numFriendRequests(vector<int>& a) {
        int n = a.size();

        unordered_map<int, int> mp;
        for (const auto& i : a) {
            mp[i]++;
        }

        int res = 0;
        for (const auto& a : mp) {
            for (const auto& b : mp) {
                if (req(a.first, b.first)) {
                    res += a.second * (b.second - (a.first == b.first));
                }
            }
        }
        return res;
    }

    bool req(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a);
    }
};