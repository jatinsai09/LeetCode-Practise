class Solution {
#define ll long long
public:
    int minJumps(vector<int>& a) {
        int n = a.size(), mx = 0;
        for (auto& i : a) {
            mx = max(mx, i);
        }
        
        vector<int> isp(mx + 1, 1);
        isp[0] = isp[1] = 0;
        vector<vector<int>> fp(mx + 1);
        for (int i = 2; i <= mx; i++) {
            if (isp[i]) {
                for (int j = i * 2; j <= mx; j += i) {
                    isp[j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int p = 2; p * p <= a[i]; p++) {
                if (a[i] % p == 0) {
                    if(isp[p]){ 
                        fp[p].push_back(i);
                    }

                    if (a[i] / p != p && isp[a[i] / p]) {
                        fp[a[i] / p].push_back(i);
                    }
                }
            }
            if (isp[a[i]]) {
                fp[a[i]].push_back(i);
            }
        }

        vector<int> vis(n + 1, 0), used(mx + 1, 0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);

        int mvs = 0;
        while (!q.empty()) {
            int hv = q.size();
            while (hv--) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) {
                    return mvs;
                }

                if (cur - 1 > 0 && !vis[cur - 1]) {
                    q.push(cur - 1);
                    vis[cur - 1] = 1;
                }
                if (cur + 1 < n && !vis[cur + 1]) {
                    q.push(cur + 1);
                    vis[cur + 1] = 1;
                }

                if (isp[a[cur]] && !used[a[cur]]) {
                    used[a[cur]] = 1;
                    for (auto& adj : fp[a[cur]]) {
                        if (!vis[adj]) {
                            q.push(adj);
                            vis[adj] = 1;
                        }
                    }
                }
            }

            mvs++;
        }

        return -1;
    }
};