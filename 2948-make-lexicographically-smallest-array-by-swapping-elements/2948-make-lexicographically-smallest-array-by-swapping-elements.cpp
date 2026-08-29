class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }
        sort(begin(vp), end(vp));

        vector<int> res(n);
        for (int i = 0; i < n;) {
            vector<int> vi = {vp[i].second};

            int j = i + 1;
            while (j < n && vp[j].first - vp[j - 1].first <= limit) {
                vi.push_back(vp[j].second);
                j++;
            }
            sort(begin(vi), end(vi));

            int k = 0;
            while (i < j) {
                res[vi[k]] = vp[i].first;
                k++;
                i++;
            }
        }
        return res;
    }
};