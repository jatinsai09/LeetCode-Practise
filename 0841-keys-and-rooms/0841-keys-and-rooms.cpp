class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        set<int> vis;
        q.push(0);
        vis.insert(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : rooms[u]) {
                if (!vis.count(v)) {
                    vis.insert(v);
                    q.push(v);
                }
            }
        }

        return vis.size() == n;
    }
};