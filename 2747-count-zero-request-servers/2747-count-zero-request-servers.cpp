class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(begin(logs), end(logs), [&](auto& l1, auto& l2){
            return l1[1] < l2[1];
        });

        int m = logs.size(), q = queries.size();
        
        vector<int> ind(q);
        for (int i = 0; i < q; i++) {
            ind[i] = i;
        }
        sort(begin(ind), end(ind), [&](int &i, int &j){
            return queries[i] < queries[j];
        });

        vector<int> res(q), f(n + 1);
        int l = 0, r = 0, d = 0;
        for (int i = 0; i < q; i++) {
            int t1 = queries[ind[i]] - x, t2 = queries[ind[i]];

            while (r < m && logs[r][1] <= t2) {
                if(++f[logs[r][0]] == 1) {
                    d++;
                }
                r++;
            }
            
            while (l < m && logs[l][1] < t1) {
                if(--f[logs[l][0]] == 0) {
                    d--;
                }
                l++;
            }

            res[ind[i]] = n - d;
        }

        return res;
    }
};