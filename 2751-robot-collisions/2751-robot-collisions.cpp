class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = positions.size();
        vector<vector<int>> robots, stack;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end());

        for (auto& robot : robots) {
            if (stack.empty() || stack.back()[2] == 'L' || robot[2] == 'R') {
                stack.push_back(robot);
                continue;
            }
            if (robot[2] == 'L') {
                bool add = true;
                while (!stack.empty() && stack.back()[2] == 'R' && add) {
                    int last = stack.back()[1];
                    if (robot[1] > last) {
                        stack.pop_back();
                        robot[1] -= 1;
                        continue;
                    } else if (robot[1] < last) {
                        stack.back()[1] -= 1;
                    } else {
                        stack.pop_back();
                    }
                    add=false;
                }
                if (add) {
                    stack.push_back(robot);
                }
            }
        }

        vector<int> res;
        sort(stack.begin(), stack.end(),
             [](vector<int>& a, vector<int>& b) { return a[3] < b[3]; });

        for (auto& robot : stack) {
            res.push_back(robot[1]);
        }
        return res;
    }
};