class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int n = 3;
        sort(begin(sides), end(sides));
        if (sides[0] + sides[1] <= sides[2]) {
            return {};
        }

        int a = sides[0], b = sides[1], c = sides[2];
        vector<double> res;
        double A = acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / M_PI;
        double B = acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / M_PI;
        double C = 180.0 - A - B;

        res = {A, B, C};
        sort(begin(res), end(res));
        return res;
    }
};