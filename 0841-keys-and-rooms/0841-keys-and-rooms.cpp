class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), seen = 0;
        queue<int> q;
        vector<int> vis(n);
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            seen++;

            for (auto& v : rooms[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return seen == n;
    }
};