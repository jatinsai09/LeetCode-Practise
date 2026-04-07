class Robot {
    int ind;
    bool moved;
    vector<pair<int, int>> pos;
    vector<int> dir;

public:
    Robot(int width, int height) {
        ind = 0;
        moved = false;

        for (int i = 0; i < width; i++) {
            pos.push_back({i, 0});
            dir.push_back(0);
        }

        for (int j = 1; j < height; j++) {
            pos.push_back({width - 1, j});
            dir.push_back(1);
        }

        for (int i = width - 2; i >= 0; i--) {
            pos.push_back({i, height - 1});
            dir.push_back(2);
        }

        for (int j = height - 2; j > 0; j--) {
            pos.push_back({0, j});
            dir.push_back(3);
        }

        dir[0] = 3;
    }

    void step(int num) {
        moved = true;
        ind = (ind + num) % pos.size();
    }

    vector<int> getPos() { return {pos[ind].first, pos[ind].second}; }

    string getDir() {
        if (!moved) {
            return "East";
        }

        if (dir[ind] == 0) {
            return "East";
        } 
        if (dir[ind] == 1) {
            return "North";
        }
        if (dir[ind] == 2) {
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