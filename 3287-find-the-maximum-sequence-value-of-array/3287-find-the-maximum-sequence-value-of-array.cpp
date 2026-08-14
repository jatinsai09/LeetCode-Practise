class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();

        bool dp1[401][201][128] = {}, dp2[401][201][128] = {};
        vector<int> l(128, n), r(128, -1);

        function<void(int, int, int)> dfs1 = [&](int i, int cnt, int cur) -> void {
            if (cnt == k) {
                l[cur] = min(l[cur], i - 1);
                return;
            }

            if (i + k < n  && !dp1[i][cnt][cur]) {
                dp1[i][cnt][cur] = true;

                dfs1(i + 1, cnt, cur);
                dfs1(i + 1, cnt + 1, cur | nums[i]);
            }
        };
        function<void(int, int, int)> dfs2 = [&](int i, int cnt, int cur) -> void {
            if (cnt == k) {
                r[cur] = max(r[cur], i + 1);
                return;
            }

            if (i >= k  && !dp2[i][cnt][cur]) {
                dp2[i][cnt][cur] = true;

                dfs2(i - 1, cnt, cur);
                dfs2(i - 1, cnt + 1, cur | nums[i]);
            }
        };
        

        dfs1(0, 0, 0);
        dfs2(n - 1, 0, 0);

        int res = 0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                if (l[i] < r[j]) {
                    res = max(res, i ^ j);
                }
            }
        }

        return res;
    }
};