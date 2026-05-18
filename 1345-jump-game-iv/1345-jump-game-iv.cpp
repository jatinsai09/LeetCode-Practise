class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int c = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int ind = q.front();
                q.pop();

                if (ind == n - 1) {
                    return c;
                }

                if (ind - 1 >= 0 && !vis[ind - 1]) {
                    q.push(ind - 1);
                    vis[ind - 1] = true;
                }
                if (ind + 1 < n && !vis[ind + 1]) {
                    q.push(ind + 1);
                    vis[ind + 1] = true;
                }

                for (auto &v: mp[arr[ind]]) {
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
                mp[arr[ind]].clear();
            }
            c++;
        }

        return -1;
    }
};