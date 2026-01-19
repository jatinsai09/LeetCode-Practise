class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), swaps = 0;
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int f = row[i], got = row[i + 1], req = f ^ 1;

            if (req != got) {
                swaps++;
                int partnerIndex = pos[req];

                swap(row[i + 1], row[partnerIndex]);

                pos[req] = i + 1;
                pos[got] = partnerIndex;
            }
        }

        return swaps;
    }
};