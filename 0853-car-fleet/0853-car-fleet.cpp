class Solution {
    struct Car {
        int pos, speed;
    };

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<Car> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i].pos = position[i];
            cars[i].speed = speed[i];
        }

        sort(begin(cars), end(cars),
             [&](auto& a, auto& b) { return a.pos < b.pos; });

        stack<float> stk;
        for (int i = 0; i < n; i++) {
            float time = (target - cars[i].pos) / (float)cars[i].speed;

            while (!stk.empty() && stk.top() <= time) {
                stk.pop();
            }
            stk.push(time);
        }

        return stk.size();
    }
};