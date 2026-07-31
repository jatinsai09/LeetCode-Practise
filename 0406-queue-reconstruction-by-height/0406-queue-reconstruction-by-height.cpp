class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(begin(people), end(people), [&](auto& a, auto& b){
            if(a[0] != b[0]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });

        for (int i = 1; i < n; i++) {
            auto t = people[i];

            int j = people[i][1], k = i - 1;
            while (k >= j) {
                people[k + 1] = people[k];
                k--;
            }
            
            people[k + 1] = t;
        }
        return people;
    }
};