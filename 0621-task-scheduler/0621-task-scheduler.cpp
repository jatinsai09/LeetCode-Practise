class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int v[26] = {0};
        int mxf = 0, sz = tasks.size();
        for (const auto& i : tasks) {
            mxf = max(mxf, ++v[i - 'A']);
        }

        int res = (mxf - 1) * (n + 1);
        res += count(v, v + 26, mxf);

        return max(sz, res);
    }
};