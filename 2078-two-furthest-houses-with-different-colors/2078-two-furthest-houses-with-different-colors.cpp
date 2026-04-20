class Solution {
public:
    int maxDistance(vector<int>& cls) {
        int n = cls.size();
        int l = 0, r = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (cls[0] ^ cls[i]) {
                l = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (cls[n - 1] ^ cls[i]) {
                r = i;
                break;
            }
        }

        return max(l, n - 1 - r);
    }
};