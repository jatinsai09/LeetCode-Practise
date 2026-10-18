class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();

        vector<int> in(n), out(n);

        unordered_map<char, char> child;
        child['R'] = 'B';
        child['B'] = 'W';
        child['W'] = 'R';

        for (auto &e: edges) {
            char c1 = colors[e[0]], c2 = colors[e[1]];

            if (c1 == c2) {
                return -1;
            }

            if (child[c1] == c2) {
                out[e[0]]++;
                in[e[1]]++;
            } else {
                out[e[1]]++;
                in[e[0]]++;
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                root = i;
            }

            if (in[i] > 1 || out[i] > 2) {
                return -1;
            }
        }

        return root;
    }
};