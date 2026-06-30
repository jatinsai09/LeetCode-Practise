class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(begin(tokens), end(tokens));
        int left = 0, right = n - 1;

        int s = 0, best = 0;
        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left++];
                s++;
            } else {
                if (s) {
                    power += tokens[right--];
                    s--;
                } else {
                    break;
                }
            }

            best = max(best, s);
        }
        return best;
    }
};