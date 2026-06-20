class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxe = *max_element(arr1.begin(), arr1.end());
        map<int, int> mp;

        for (auto& i : arr1) {
            mp[i]++;
        }

        vector<int> res;
        for (auto& i : arr2) {
            while (mp[i]) {
                res.push_back(i);
                mp[i]--;
            }
        }

        for (auto& it : mp) {
            int f = it.second;
            for (int i = 0; i < f; i++) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};