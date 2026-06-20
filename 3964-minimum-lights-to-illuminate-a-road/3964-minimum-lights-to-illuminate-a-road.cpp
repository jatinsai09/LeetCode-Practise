class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> vis(n + 1);
        for (int i = 0; i < n; i++) {
            if (lights[i]) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
                vis[l] += 1;
                vis[r + 1] -= 1;
            }
        }
        for (int i = 1; i < n; i++) {
            vis[i] += vis[i - 1];
        }

        int res = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
            } else {
                res += (c + 2) / 3;
                c = 0;
            }
        }
        res += (c + 2) / 3;

        return res;
    }
};