class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1 = 0, e2 = 0, c1 = 0, c2 = 0;
        int t = nums.size()/3;

        for (auto& i:nums) {
            if (c1 == 0 && i != e2) {
                e1 = i;
                c1 = 1;
            } else if (c2 == 0 && i != e1) {
                e2 = i;
                c2 = 1;
            } else if (e1 == i) {
                c1++;
            } else if (e2 == i) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;
        for (auto& i:nums) {
            if (i == e1) {
                c1++;
            }
            else if (i == e2) {
                c2++;
            }
        }

        vector<int> res;
        if (c1 > t) {
            res.push_back(e1);
        }
        if (c2 > t) {
            res.push_back(e2);
        }

        return res;
    }
};