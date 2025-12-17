class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1;
        int leftmax = 0, rightmax = 0, res = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < leftmax) {
                    res += leftmax - height[l];
                } else {
                    leftmax = height[l];
                }
                l++;
            } else {
                if (height[r] < rightmax) {
                    res += rightmax - height[r];
                } else {
                    rightmax = height[r];
                }
                r--;
            }
        }

        return res;
    }
};