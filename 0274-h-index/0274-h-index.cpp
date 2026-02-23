class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        
        int n = citations.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (citations[mid] >= mid + 1) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};