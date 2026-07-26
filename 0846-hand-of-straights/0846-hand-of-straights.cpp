class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int len) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = hand.size();
        if (n % len) {
            return false;
        }

        sort(begin(hand), end(hand));
        
       for (int i = 0; i < n; i++) {
            if (hand[i] == -1) {
                continue;
            }

            int t = i + 1;
            for (int j = 1; j < len; j++) {
                while (t < n && hand[t] != hand[i] + j) {
                    t++;
                }

                if (t == n) {
                    return false;
                }

                hand[t] = -1;
                t++;
            }
       }

       return true;
    }
};