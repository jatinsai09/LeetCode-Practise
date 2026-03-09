class Solution {
public:
    int minimumIndex(vector<int>& cap, int is) {
        int n = cap.size(), ind = -1;

        for (int i = 0; i < n; i++) {
            if (cap[i] >= is) {
                if (ind == -1 || cap[i] < cap[ind]) {
                    ind = i;
                }
            }
        }

        return ind;
        
    }
};