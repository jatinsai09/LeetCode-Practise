class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> res(n + 1);
        for (auto& t : trust) {
            res[t[0]]--; // outgoing
            res[t[1]]++; // incoming
        }

        for (int i = 1; i <= n; i++) {
            if (res[i] == n - 1) { // indegree == n - 1 && outdegree == 0
                return i; 
            }
        }

        return -1;
    }
};