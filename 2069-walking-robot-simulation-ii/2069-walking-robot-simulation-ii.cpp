class Robot {
    vector<vector<int>> direc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // E N W S
    int n, m;
    int x, y;
    int dir;
    int cyc;

public:
    Robot(int width, int height) {
        x = 0, y = 0;
        dir = 0;

        n = height;
        m = width;

        cyc = 2 * (n + m - 2);
    }

    void step(int num) {
        int d = num;

        int newX = x, newY = y;
        int canX, canY;

        d %= cyc;

        if (d == 0 && x == 0 && y == 0) {
            dir = 3;
            return;
        }

        while (d > 0) {
            if (dir == 0) {
                canX = m - 1 - x;
                if (d <= canX) {
                    x += d;
                    return;
                } else {
                    d -= canX;
                    newX = m - 1;
                    dir++;
                }
            } else if (dir == 1) {
                canY = n - 1 - y;
                if (d <= canY) {
                    y += d;
                    return;
                } else {
                    d -= canY;
                    newY = n - 1;
                    dir++;
                }
            } else if (dir == 2) {
                canX = x;
                if (d <= canX) {
                    x -= d;
                    return;
                } else {
                    d -= canX;
                    newX = 0;
                    dir++;
                }
            } else {
                canY = y;
                if (d <= canY) {
                    y -= d;
                    return;
                } else {
                    d -= canY;
                    newY = 0;
                    dir++;
                }
            }

            x = newX, y = newY;
            dir %= 4;
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (dir == 0) {
            return "East";
        }
        if (dir == 1) {
            return "North";
        }
        if (dir == 2) {
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */