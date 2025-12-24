class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size(), res = 0;
        int left = accumulate(begin(apple), end(apple), 0);
        sort(rbegin(capacity), rend(capacity));

        while (left > 0) {
            left -= capacity[res++];
        }

        return res;
    }
};