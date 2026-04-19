class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), c = INT_MIN;
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < c) {
                return true;
            }
            
            while (!s.empty() && s.top() < nums[i]) {
                c = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};