class Solution {
public:
    int reverse(int n) {
        int rev = 0, d;
        while (n) {
            d = n % 10;
            rev = rev * 10 + d;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;

        unordered_map<int, int> rev;
        for (int j = 0; j < n; j++) {
            if (rev.find(nums[j]) != rev.end()) {
                res = min(res, j - rev[nums[j]]);
            }
            
            rev[reverse(nums[j])] = j;
        }

        return (res == INT_MAX ? -1 : res);
    }
};