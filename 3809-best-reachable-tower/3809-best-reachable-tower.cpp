class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int mx = center[0], my = center[1];
        int x = -1, y = -1, mxq = -1;

        for (auto& t: towers) {
            int xi = t[0], yi = t[1], qi = t[2];
            if (abs(mx - xi) + abs(my - yi) <= radius) {
                if (qi > mxq) {
                    x = xi;
                    y = yi;
                    mxq = qi;
                } else if (qi == mxq && (xi < x || (xi == x && yi < y))) {
                    x = xi;
                    y = yi;
                } 
            }
        }

        return {x, y};
    }
};