class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0 && dp[i - minJump]) {
                prev++;
            }

            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                prev--;
            }

            dp[i] = (prev > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};