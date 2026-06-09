class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max_candies = *max_element(candies.begin(), candies.end());
        max_candies -= extraCandies;

        vector<bool> res(candies.size(), true);

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] < max_candies) {
                res[i] = false;
            }
        }
        return res;
    }
};