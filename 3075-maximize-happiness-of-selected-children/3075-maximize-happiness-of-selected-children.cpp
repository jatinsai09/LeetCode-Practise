class Solution {
#define ll long long int
public:
    long long maximumHappinessSum(vector<int>& hp, int k) {
        ll n = hp.size();
        sort(begin(hp), end(hp));

        ll c = 0, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c == k) {
                break;
            }
            sum += max(hp[i] - c, 0LL);
            c++;
        }

        return sum;
    }
};