class Solution {
#define ll long long int 
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xClose, yClose;

        xClose = max(x1, min(x2, xCenter));
        yClose = max(y1, min(y2, yCenter));

        ll dx = xCenter - xClose, dy = yCenter - yClose;

        return (dx * dx + dy * dy) <= 1LL * radius * radius;
    }
};