class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max_candies = *max_element(candies.begin(), candies.end());

        vector<bool> res(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max_candies) {
                res[i] = true;
            }
        }
        return res;
    }
};