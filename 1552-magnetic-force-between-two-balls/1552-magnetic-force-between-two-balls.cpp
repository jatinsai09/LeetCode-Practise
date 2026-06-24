class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int l = 1, r = position.back() - position[0];

        int res = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can_place(position, m, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }

    bool can_place(vector<int> position, int m, int d) {
        int c = 1, prev = position[0];
        for (auto &p: position) {
            if (p - prev >= d) {
                c++;
                prev = p;
            }
            if (c >= m) {
                return true;
            }
        }
        return false;
    }
};