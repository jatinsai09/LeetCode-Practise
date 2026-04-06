class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<string, bool> mp;
        for (const auto& it : obstacles) {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            mp[key] = true;
        }
        vector<vector<int>> direc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // according to order W N E S

        int dir = 1; // i.e. north
        // 0: west, 1: north, 2: east, 3: south
        int x = 0, y = 0;
        int mxDist = 0;
        for (const auto& it : commands) {
            if (it == -2) {
                // move left
                dir = (dir + 3) % 4;
            } else if (it == -1) {
                // move right
                dir = (dir + 1) % 4;
            } else {
                int k = it, newX, newY;
                for (int i = 1; i <= k; i++) {
                    newX = x + direc[dir][0];
                    newY = y + direc[dir][1];

                    string key = to_string(newX) + "+" + to_string(newY);
                    if (mp.find(key) != mp.end()) {
                        // obstacle has been found so don't go there
                        break;
                    }

                    x = newX, y = newY;
                    mxDist = max(mxDist, x * x + y * y);
                }
            }
        }

        return mxDist;
    }
};
