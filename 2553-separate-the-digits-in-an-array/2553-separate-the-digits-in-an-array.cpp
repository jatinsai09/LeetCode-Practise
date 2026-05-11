class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto &i: nums) {
            string s = to_string(i);
            for (char &c: s) {
                res.push_back(c - '0');
            }
        }
        return res;
    }
};