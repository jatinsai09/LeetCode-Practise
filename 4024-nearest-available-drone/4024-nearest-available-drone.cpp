class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size(), mn = INT_MAX, ind = -1;

        for (int i = 0; i < n; i++) {
            int dist = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);

            if (dist <= drones[i][2]) {
                if (dist < mn) {
                    ind = i;
                    mn = dist;
                }
            }
        }

        return ind;
    }
};