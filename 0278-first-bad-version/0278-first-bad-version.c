// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int
int firstBadVersion(int n) {
    ll l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}