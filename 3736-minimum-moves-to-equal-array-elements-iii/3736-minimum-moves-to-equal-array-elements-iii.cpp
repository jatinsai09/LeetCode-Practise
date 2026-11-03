class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        
        int mx = 0, sum = 0;
        for(auto &i: nums) {
            mx = max(mx, i);
            sum += i;
        }
        return mx * n - sum;
    }
};