class Solution {
public:
    unordered_set<int> vis;
    bool canReach(vector<int>& arr, int st) {
        if (st < 0 || st >= arr.size() || !vis.insert(st).second) {
            return false;
        }
        vis.insert(st);

        return arr[st] == 0 || canReach(arr, st + arr[st]) ||
               canReach(arr, st - arr[st]);
    }
};