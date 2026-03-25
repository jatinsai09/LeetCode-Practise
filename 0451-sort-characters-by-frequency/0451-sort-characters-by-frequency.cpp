class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (auto& x : s) {
            f[x]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto& it : f) {
            pq.push({it.second, it.first});
        }

        string res = "";
        while (pq.size() > 0) {
            int f = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            while (f--) {
                res += c;
            }
        }
        return res;
    }
};