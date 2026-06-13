class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        auto find = [&](int n) -> bool {
            int req = 0;
            for (auto& p: piles) {
                req += (p + n - 1) / n;

                if (req > h) {
                    return false;
                }
            }
            return true;
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (find(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};