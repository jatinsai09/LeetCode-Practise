class Solution {
#define ll long long int
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        function<ll(ll)> noOfTrips = [&](ll hv) -> ll {
            ll got = 0;
            for (const auto &i: time) {
                got += hv / i;
            }

            return got;
        };

        ll l = 1, r = 1e14, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;

            if (noOfTrips(mid) >= totalTrips) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};