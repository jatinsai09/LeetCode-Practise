class Solution {
private:
    void merge(auto& vp, int l, int m, int r, auto& res) {
        vector<pair<int, int>> t(r - l + 1);

        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r)
        {
            if (vp[i].first <= vp[j].first) {
                res[vp[i].second] += (j - m - 1);
                t[k++] = vp[i++];
            } else {
                t[k++] = vp[j++];
            }
        }

        while(i <= m) { 
            t[k++] = vp[i];
            res[vp[i].second] += (j - m - 1);
            i++;
        }
        while(j <= r) t[k++] = vp[j++];

        for (int i = l; i <= r; i++) {
            vp[i] = t[i - l];
        }
    }   

    void mergeSort(auto& vp, int l, int r, auto& res) {
        if (l >= r) {
            return;
        }

        int m = (l + r) >> 1;

        mergeSort(vp, l, m, res);
        mergeSort(vp, m + 1, r, res);

        merge(vp, l, m, r, res);
    } 
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        vector<int> res(n);
        mergeSort(vp, 0, n - 1, res);

        return res;
    }
};