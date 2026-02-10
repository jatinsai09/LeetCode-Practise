class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n = a.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> e, o;
            for (int j = i; j < n; j++) {
                if(a[j] & 1) {
                    o.insert(a[j]);
                } else {
                    e.insert(a[j]);
                }
                if(e.size() == o.size()) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};