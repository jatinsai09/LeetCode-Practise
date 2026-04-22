class Solution {
struct Car {
    int pos;
    double time;
};
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size(), res = 0;
        vector<Car> vp(n);

        for (int i = 0; i < n; i++) {
            vp[i] = {position[i], (target - position[i]) / (1.0 * speed[i])};
        }
        sort(begin(vp), end(vp), [&](auto& a, auto& b){
            return a.pos < b.pos;
        });

        res = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (vp[i].time <= vp[i + 1].time) {
                vp[i].time = vp[i + 1].time;
            } else {
                res++;
            }
        }
        return res;
    }
};