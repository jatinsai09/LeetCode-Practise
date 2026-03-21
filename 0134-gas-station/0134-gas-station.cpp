class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), total = 0;
        int cur = 0, start = 0;

        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            
            if (cur < 0) {
                cur = 0;
                start = i + 1;
            }
        }
        return (total < 0) ? -1 : start;
    }
};